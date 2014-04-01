/*!
 * \file Point.c
 * \brief Implémentation de la class point.
 * \author GARRONE Joseph, joseph.garrone@ensimag.grenoble-inp.fr
 * \version 0.1
 */

#include "Point.h"

template< typename T > struct TypeIsFloat{ static const bool value = false; };
template< typename T > struct TypeIsDouble{ static const bool value = false; };

template<> struct TypeIsFloat< float >{ static const bool value = true; };
template<> struct TypeIsDouble< double >{ static const bool value = true; };

template<typename T>
Point<T>::Point(T x,T y){
	if ( !TypeIsFloat<T>::value && !TypeIsDouble<T>::value ) throw std::exception("IncompatibleType");
	m_x = x;
	m_y = y;
}
