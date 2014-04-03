/*!
 * \file Point.h
 * \brief Classe générique de points bidimentionelle.
 * \author GARRONE Joseph, joseph.garrone@ensimag.grenoble-inp.fr
 * \version 0.1
 */

#ifndef POINT_H
#define POINT_H
#include <iostream> //Pour cout
#include <cassert> //Pour les assert.
#include <stdexcept>

template <typename T> class Point{
	public :

		/*! 
		 *\brief Constructeur par default
		 *
		 *Initialise le point a (0,0).
		 *
		 */
		Point(): m_x((T)0), m_y((T)0){};
		/*! 
		 *\brief Constructeur 
		 *
		 *\param T x, T y
		 *
		 * Le type T doit être double ou int.
		 *
		 */
		Point(T x, T y);

		/*! 
		 *\brief Destructeur
		 *
		 */
		//~Point(){};

		/*! 
		 *\brief x
		 *
		 *Acces en lécture au champs x
		 *
		 *\return T
		 */
		T x() const{ return m_x; };

		/*! 
		 *\brief y
		 *
		 *Acces en lécture au champs y
		 *
		 *\return T
		 */

		T y() const{ return m_y; };


		bool operator == (const Point<T> &other ) const;

		void transformer( T m11, T m12, T m21, T m22);
		void deplacer( T dx, T dy);

	private :
		T m_x;
		T m_y;
};

/* IMPLEMENTAITION */
using namespace std;

template< typename T > struct TypeIsFloat{ static const bool value = false; };
template< typename T > struct TypeIsDouble{ static const bool value = false; };

template<> struct TypeIsFloat< float >{ static const bool value = true; };
template<> struct TypeIsDouble< double >{ static const bool value = true; };

template<typename T> Point<T>::Point(T x,T y){
	if ( !TypeIsFloat<T>::value && !TypeIsDouble<T>::value ) throw domain_error("Les Element de point sont float ou double");
	m_x = x;
	m_y = y;
}

template<typename T> 
bool Point<T>::operator == (const Point<T> &other ) const{
	if( this == &other )return true;
	return m_x==other.x() && m_y==other.y();
}

template<typename T> 
void Point<T>::transformer( T m11, T m12, T m21, T m22){
	m_x = m_x * m11 + m_y * m21; 
	m_y = m_x * m12 + m_y * m22; 
}

template<typename T> 
void Point<T>::deplacer( T dx, T dy){
	m_x = m_x + dx; 
	m_y = m_x + dy; 
}
#endif
