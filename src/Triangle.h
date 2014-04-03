/*!
 * \file Triangle.h
 * \brief Classe Triangle
 * \author GARRONE Joseph, joseph.garrone@ensimag.grenoble-inp.fr
 * \version 0.1
 */

#ifndef TRIANGLE_H
#define TRIANGLE_H
#include "Point.h"
template< typename T> class Triangle{
	public :
		Triangle(): m_p1(0,0), m_p2(0,0), m_p3(0,0) {};
		Triangle(Point<T> p1, Point<T> p2, Point<T> p3): m_p1(p1), m_p2(p2), m_p3(p3) {};

		Point<T> p1() const { return m_p1; };
		Point<T> p2() const { return m_p2; };
		Point<T> p3() const { return m_p3; };

		void display() const;

		void transformer( T m11, T m12, T m21, T m22);
		void deplacer( T dx, T dy );

	private :
		Point<T> m_p1;
		Point<T> m_p2;
		Point<T> m_p3;
};


template< typename T>
void Triangle< T >::display() const{
	std::cout << '(' << m_p1.x() << ',' << m_p1.y() << ')';
	std::cout << '(' << m_p2.x() << ',' << m_p2.y() << ')';
	std::cout << '(' << m_p3.x() << ',' << m_p3.y() << ')';
	std::cout << endl;
}

template< typename T>
void Triangle<T>::transformer( T m11, T m12, T m21, T m22){
	m_p1.transformer(m11, m12, m21, m22);
	m_p2.transformer(m11, m12, m21, m22);
	m_p3.transformer(m11, m12, m21, m22);
}


template< typename T>
void Triangle<T>::deplacer( T dx, T dy){
	m_p1.deplacer(dx, dy);
	m_p2.deplacer(dx, dy);
	m_p3.deplacer(dx, dy);
}
#endif
