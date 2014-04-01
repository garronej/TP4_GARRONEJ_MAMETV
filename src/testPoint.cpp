/*!
 * \file test.cpp
 * \brief Fichier de tests unitaires.
 * \author GARRONE Joseph, joseph.garrone@ensimag.grenoble-inp.fr
 * \version 0.1
 */

#define EXIT_SUCCESS 0
#include <iostream> //std::cout, std::cin 
#include <exception>
#include <cassert>

#include "Point.h"

using namespace std;

int main ( int argc, char *argv[] ) {
	cout	<< "\nProgram " << argv[0] << endl << endl;

	Point<float> P(3.5, 4.4);

	assert(P.x() ==(float)3.5);
	cout << "PASS" << endl;


	assert(P.y() == (float)4.4);
	cout << "PASS" << endl;


	Point<double> M(3.4, 7.4);


	assert(M.x() == (double)3.4);
	cout << "PASS" << endl;

	assert(M.y() == (double)7.4);
	cout << "PASS" << endl;


	try {
		Point<int> I(3.3, 4.3);
	}catch( exception &e){
	       	cout << "PASS" << endl;
	}

	return EXIT_SUCCESS;
}
