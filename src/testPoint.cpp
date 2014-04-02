/*!
 * \file test.cpp
 * \brief Fichier de tests unitaires.
 * \author GARRONE Joseph, joseph.garrone@ensimag.grenoble-inp.fr
 * \version 0.1 */

#define EXIT_SUCCESS 0
#include <iostream> //std::cout, std::cin 
#include <exception> //pour les exception
#include <cassert> //Pour les assert

#include <vector>
#include <list>

#include "Point.h"
#include "Triangle.h"
#include "Maillage.h"

using namespace std;

int main ( int argc, char *argv[] ) {
	cout	<< "\nProgram " << argv[0] << endl << endl;

	Point<float> P(3.5, 4.4);

	assert(P.x() ==(float)3.5);
	assert(P.y() == (float)4.4);
	cout << "PASS" << endl;


	Point<double> M(3.4, 7.4);


	assert(M.x() == (double)3.4);
	assert(M.y() == (double)7.4);
	cout << "PASS" << endl;


	try {
		Point<int> I(3.3, 4.3);
	}catch( exception &e){
	       	cout << "PASS" << endl;
	}

	Triangle<double> T(Point<double>(0,1),Point<double>(1,0), M);
	assert(T.p1().x() == (double)0);
	assert(T.p1().y() == (double)1);
	assert(T.p2().x() == (double)1);
	assert(T.p2().y() == (double)0);
	assert(T.p3().x() == (double)3.4);
	assert(T.p3().y() == (double)7.4);
	cout << "PASS" << endl;

	Maillage<double, vector> Mv(1,1, Point<double>(0,0));

	cout << "Mv" << endl;
	cout << Mv;


	Maillage<double, list> Ml(1,1, Point<double>(0,0));
	
	cout << "Ml" << endl;
	cout << Ml << endl;

	return EXIT_SUCCESS;
}
