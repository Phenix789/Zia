/**
 * @file Define.h
 * @brief Basic define for header information
 */

#pragma once
#define	__DEFINE_H__

/**
 * @def __delegate
 * @brief Information sur la gestion de la memoire
 * __delegate est un indicateur pour la gestion memoire, il a deux significations :
 *  - En retour de fonction/method, il informe que le pointeur retourné est a la responsabilité de l'appelant.
 *  - En parametre de fonction/method, il informe que le pointeur passe sous la responsabilité de l'appelé.
 */
#define __delegate

/**
 * @def __static
 * @brief Information sur la gestion de la memoire
 * Une fonction/method retournant un parametre static informe que celui ci est interne a la structure.
 * Cela peut avoir plusieurs effet tels que:
 *  - Si c'est un pointeur, la gestion de la memoire n'est pas a la charge de l'appelant.
 *  - Un second appel a la fonction/method peut modifier la valeur du premier (variable static interne).
 */
#define __static

/**
 * @def __throw
 * @brief La fonction/method est suceptible de lancer une exception. Le nom de l'exception lancé peut etre specifié
 */
#define __throw
#define __throw1(e1)
#define __throw2(e1, e2)
#define __throw3(e1, e2, e3)
#define __throw4(e1, e2, e3, e4)

#if defined _WIN32
# define WINDOWS
# include <WinSock2.h>
# include <Windows.h>

#define __typename
#pragma warning(disable: 4250)
#pragma warning(disable: 4244)
#pragma warning(disable: 4355)
#pragma warning(disable: 4722)

#elif defined unix
# define LINUX

#define __typename typename
#endif
