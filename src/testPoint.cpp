/*!
 * \file test.cpp
 * \brief Fichier de tests unitaires.
 * \author GARRONE Joseph, joseph.garrone@ensimag.grenoble-inp.fr
 * \version 0.1
 */


#define EXIT_SUCCESS 0
#include <iostream> //std::cout, std::cin 

#include "Point.h"

using namespace std;

int main ( int argc, char *argv[] ) {
	cout	<< "\nProgram " << argv[0] << endl << endl;

	Point<float> P(3.5, 4.4);
	cout << P.x() << endl;
	cout << P.y() << endl;

	Point<double> M(3.4, 7.4);
	cout << M.x() << endl;
	cout << M.y() << endl;

	return EXIT_SUCCESS;
}

