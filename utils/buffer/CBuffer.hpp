/**
 *
 *
 *
 */

#pragma once
#define __CBUFFER_HPP__

#include "Array.hpp"

namespace utils {

	template <typename T, int dataSize>
	class CBuffer {
	protected:
		int index;
		int dataIndex;
		T data[dataSize];
		bool deleteAfterReading;
		bool addData;

	public:
		CBuffer(bool deleteDataAfterReading = false, bool addDataInsteadOfAssigning = false)
		: index(0), dataIndex(0), deleteAfterReading(deleteDataAfterReading), addData(addDataInsteadOfAssigning) {
			std::memset(reinterpret_cast<void *> (data), 0, dataSize);
		}

		virtual ~CBuffer() {

		}

		virtual void fillBuffer(const T * othData, int size, int bufferIndex = -1, bool useDataIndex = true) {
			if (bufferIndex == -1) {
				bufferIndex = dataIndex;
			}
			for (int i = 0; i < size; ++i) {

				if (addData) {
					data[bufferIndex] += othData[i];
				}
				else {
					data[bufferIndex] = othData[i];
				}
				bufferIndex++;
				if (bufferIndex >= dataSize) {
					bufferIndex = 0;
				}
			}
			if (useDataIndex) {
				dataIndex = bufferIndex;
			}
		}

		virtual void fillBuffer(Array<T> & othData, int bufferIndex = -1, bool useDataIndex = true) {
			fillBuffer(othData.getData(), othData.size(), bufferIndex, useDataIndex);
		}

		virtual void cpyToBuffer(Array<T> & othData, int size) {
			if (othData.size() >= size) {
				cpyToBuffer(othData.getData(), size);
				othData.setUsedSize(size);
			}
		}

		virtual void cpyToBuffer(Array<T> & othData) {
			cpyToBuffer(othData.getData(), othData.size());
			othData.setUsedSize(othData.size());
		}

		virtual void cpyToBuffer(T * othBuffer, int othSize) {
			for (int i = 0; i < othSize; i++) {
				othBuffer[i] = getNextData();
			}
		}

		virtual inline T getNextData() {
			T & c = data[index];
			if (deleteAfterReading) {
				data[index] = 0;
			}
			index++;
			if (index >= dataSize) {
				index = 0;
			}
			return c;
		}

		virtual void pushDataIndex(int amount) {
			int newDataIndex = dataIndex + amount;
			while (newDataIndex >= dataSize) {
				newDataIndex -= dataSize;
			}
			dataIndex = newDataIndex;
		}

		virtual int getDataSize() {
			int nbData = (index - dataIndex) % dataSize;
			return (nbData > 0) ? nbData : -nbData;
		}

		virtual int size() {
			return dataSize;
		}

		virtual int getIndex() {
			return index;
		}

		virtual int getDataIndex() {
			return dataIndex;
		}

	};

}
