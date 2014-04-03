/*!
 * \file Maillage.h
 * \brief ClasseMaillage
 * \author GARRONE Joseph, joseph.garrone@ensimag.grenoble-inp.fr
 * \version 0.1
 */ 
#ifndef MAILLAGE_H
#define MAILLAGE_H

#include <iostream>
#include <list>
#include <vector>
#include <cmath>

#include "Triangle.h"
#include "Point.h"


/*! 
 *\class Maillage *
 *\brief Maillage réctangulaire.
 *
 * Deux paramètre template :
 * 1er : Définie la présisiopn de définition des points : double ou float
 * 2e : Conteuneur stl pour stroker les triangle commposant le maillage.
 * 	Le choix de du contener n'a d'effet que sur les performance.
 * 	On ne peux passer que des séquence container les trillangle n'étant pas assosier a une clef.
 * 	std::vector, std::list, std::deque, std::forwrd_list
 *Ex de construction: Maillage< double, std:list > M(3, 4, Point(0, 0) )
 * 
 */
template< typename T, template< typename=Triangle<T>, typename=std::allocator< Triangle<T> > > class C> class Maillage{

	private :
		C< Triangle<T> > m_data; /*!< Contener des triangles.  */

		//std::list< std::vector< Point<T> > > m_ends; /*!< List de vecteur de 4 points délimitant les maillages.*/
	public : 

		/*! 
		 *\brief Constructeur
		 *
		 *Construit un maillage de triangle.
		 *
		 *\param 
		 *
		 *\return
		 */
		Maillage(int m, int n, const Point<T>& origine);
		Maillage(const Point<T> &p1, const Point<T> &p2, const Point<T> &p3, const Point<T> &p4, int m, int n);

		/*! 
		 *\brief fusion de deux map
		 *
		 *Test rigoureux de non superposition
		 *
		 *Permet de fusioner deux maillage qui ne se recouvre pas.
		 *
		 *\param const Maillage<T,C>& m
		 *
		 */
		void fusioner( const Maillage<T,C>& m);

		void transformer( T m11, T m12, T m21, T m22);
		void deplacer( T dx, T dy );
		void tourner( T angle, const Point<T>& pt );

		typename C< Triangle<T> >::const_iterator beginiter() const{ return m_data.begin(); };
		typename C< Triangle<T> >::const_iterator enditer() const { return m_data.end(); };

};
/*  Implémentation */
using namespace std;

template< typename T, template< typename=Triangle<T>, typename=std::allocator< Triangle<T> > > class C>
Maillage<T,C>::Maillage(int m, int n, const Point<T>& origine ){

	//	vector< Point<T> > end1(4, Point<T>());
	//	end1[0] = origine;
	//	end1[1] = Point<T>(origine.x() +m, origine.y());
	//	end1[2] = Point<T>(origine.x() +m , origine.y() +n);
	//	end1[3] = Point<T>(origine.x() , origine.y() + n);
	//
	//	m_ends.assign(1, end1);


	m_data.assign(2*n*m, Triangle<T>() );
	typename C< Triangle<T> >::iterator it = m_data.begin();

	for( T x = origine.x(); x < origine.x()+m; x++){
		for( T y = origine.y(); y < origine.y()+n; y++){
			*(it++) = Triangle<T>(Point<T>(x,y), Point<T>(x,y+1),Point<T>(x+1,y));
			*(it++) = Triangle<T>(Point<T>(x+1,y+1), Point<T>(x,y+1),Point<T>(x+1,y));
		}
	}
}

template< typename T, template< typename=Triangle<T>, typename=std::allocator< Triangle<T> > > class C>
Maillage<T,C>::Maillage(const Point<T> &p1, const Point<T> &p2, const Point<T> &p3, const Point<T> &p4, int m, int n) {

	m_data.assign(2*n*m, Triangle<T>() );
	typename C< Triangle<T> >::iterator it = m_data.begin();

	for( T x = p1.x(); x < p1.x()+m; x++){
		for( T y = p1.y(); y < p1.y()+n; y++){
			*(it++) = Triangle<T>(Point<T>(x,y), Point<T>(x,y+1),Point<T>(x+1,y));
			*(it++) = Triangle<T>(Point<T>(x+1,y+1), Point<T>(x,y+1),Point<T>(x+1,y));
		}
	}

	T P1P2_2 = ( p2.x() - p1.x() )*( p2.x() - p1.x() ) + ( p2.y() - p1.y() )*( p2.y() - p1.y() );
	T P2P3_2 = ( p3.x() - p2.x() )*( p3.x() - p2.x() ) + ( p3.y() - p2.y() )*( p3.y() - p2.y() );
	T P3P4_2 = ( p4.x() - p3.x() )*( p4.x() - p3.x() ) + ( p4.y() - p3.y() )*( p4.y() - p3.y() );
	T P1P4_2 = ( p4.x() - p1.x() )*( p4.x() - p1.x() ) + ( p4.y() - p1.y() )*( p4.y() - p1.y() );
	T P1P2xP1P4 = ( p2.x() - p1.x() ) * ( p4.x() - p1.x() ) + ( p2.y() - p1.y() ) * ( p4.y() - p1.y() );
	if( !( P1P2xP1P4 == 0 && P1P2_2 == P3P4_2 && P2P3_2 == P1P4_2 )) throw domain_error("Les Points ne formes pas un réctangle");
	transformer( sqrt(P1P2_2)/m, 0, sqrt(P1P4_2)/n, 0);
	T a = ( p2.x() - p1.x() )/ sqrt(P1P2_2);
	T b = ( p2.y() - p1.y() )/ sqrt(P1P2_2);
	transformer( a, -b, b, a);
	deplacer( p1.x(), p1.y() );
}

template< typename T, template< typename=Triangle<T>, typename=std::allocator< Triangle<T> > > class C>
ostream & operator<<( ostream &str, const Maillage<T,C> &M){
	for( typename C< Triangle< T > >::const_iterator it = M.beginiter(); it != M.enditer(); it++){
		str << it->p1().x() << ' ' << it->p1().y() << endl;
		str << it->p2().x() << ' ' << it->p2().y() << endl;
		str << it->p3().x() << ' ' << it->p3().y() << endl;
		str << it->p1().x() << ' ' << it->p1().y() << endl;
		str << endl;
	}
	return str;
}

template< typename T, template< typename=Triangle<T>, typename=std::allocator< Triangle<T> > > class C>
void Maillage<T,C>::fusioner( const Maillage<T,C>& m){

	//Pour Tous les point dans m.m_ends 
	//On vérifie s'il n'es pas inclu dans un des réctangle de ce maillage.
	//Point<T> M,P1,P2,P3,P4;
	//T P1MxP1P2, P1P2_2, P1MxP1P4, P1P4_2;
	//bool sup;

	//for( typename list< vector< Point<T> > >::const_iterator itM = m.m_ends.begin(); itM!=m.m_ends.end(); itM++){

	//	for( int i=0; i<4; i++){
	//		M = (*itM)[i];
	//		sup = true;
	//		for( typename list< vector<Point<T> > >::iterator it = m_ends.begin(); it!=m_ends.end(); it++){
	//			P1 = (*it)[0];
	//			P2 = (*it)[1];
	//			P3 = (*it)[2];
	//			P4 = (*it)[3];

	//			P1MxP1P2 =(M.x()-P1.x())*(P2.x()-P1.x())+(M.y()-P1.y())*(P2.y()-P1.y());
	//			P1P2_2 = (P2.x()-P1.x())*(P2.x()-P1.x())+(P2.y()-P1.y())*(P2.y()-P1.y());
	//			P1MxP1P4 =(M.x()-P1.x())*(P4.x()-P1.x())+(M.y()-P1.y())*(P4.y()-P1.y());
	//			P1P4_2 = (P4.x()-P1.x())*(P4.x()-P1.x())+(P4.y()-P1.y())*(P4.y()-P1.y());

	//			if( 0< P1MxP1P2 && P1MxP1P2<P1P2_2 && 0<P1MxP1P4 && P1MxP1P4<P1P4_2) throw domain_error("Superposition");

	//			sup = sup && ( M == P1 || M == P2 || M == P3 || M == P4 );
	//		}
	//		if( sup ) throw domain_error("Superposition complète de deux maillage");
	//	}
	//}
	//for( typename list< vector< Point<T> > >::const_iterator itM = m.m_ends.begin(); itM!=m.m_ends.end(); itM++) m_ends.push_back( (*itM) );
	for( typename C< Triangle< T > >::const_iterator it = m.beginiter(); it != m.enditer(); it++) m_data.push_back( *it );

}

template< typename T, template< typename=Triangle<T>, typename=std::allocator< Triangle<T> > > class C>
void Maillage<T,C>::transformer( T m11, T m12, T m21, T m22){
	for( typename C< Triangle< T > >::iterator it = m_data.begin(); it != m_data.end(); it++) it->transformer(m11, m12, m21, m22);
}



template< typename T, template< typename=Triangle<T>, typename=std::allocator< Triangle<T> > > class C>
void Maillage<T,C>::deplacer( T dx, T dy ){
	for( typename C< Triangle< T > >::iterator it = m_data.begin(); it != m_data.end(); it++){
		it->deplacer(dx, dy);
	}

}

template< typename T, template< typename=Triangle<T>, typename=std::allocator< Triangle<T> > > class C>
void tourner( T angle, const Point<T>& pt ){
	deplacer(-pt.x(),-pt.y());
	transformer( cos(angle),-sin(angle),sin(angle),cos(angle));
	deplacer(pt.x(),pt.y());
}
#endif
