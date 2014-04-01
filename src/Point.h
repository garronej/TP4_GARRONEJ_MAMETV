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

template <typename T>
class Point{
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
		Point(T x,T y);

		/*! 
		 *\brief Destructeur
		 *
		 */
		~Point(){};

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

	private :
		T m_x;
		T m_y;
};

#endif
