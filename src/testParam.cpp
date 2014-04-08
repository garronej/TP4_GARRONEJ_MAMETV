/*!
 * \file test.cpp
 * \brief Fichier de tests unitaires.
 * \author GARRONE Joseph, joseph.garrone@ensimag.grenoble-inp.fr
 * \version 0.1 */
#define EXIT_SUCCESS 0 
#include <iostream> //std::cout, std::cin 
#include <cstdlib>

#include <vector>
#include <list>

#include "Point.h"
#include "Triangle.h"
#include "Maillage.h"

using namespace std;

int main ( int argc, char *argv[] ) {
	cout	<< "\nProgram " << argv[0] << endl << endl;


		int m = atoi(argv[1]);
		int n = atoi(argv[2]);

		cout<< "m = " << m << endl;
		cout<< "n = " << n << endl;

	if ( atoi(argv[3]) == 1){
		cout << "list" << endl;
		Maillage<float,list> M(Point<float>(2,3), Point<float>(5,6), Point<float>(3,8), Point<float>(0,5), m/4, n);
		Maillage<float,list> N(Point<float>(2,3), Point<float>(5,6), Point<float>(3,8), Point<float>(0,5), 2*m, n);
		M.fusionner(N);
	}else{
		cout << "vector" << endl;
		Maillage<float,vector> M(Point<float>(2,3), Point<float>(5,6), Point<float>(3,8), Point<float>(0,5), m/4, n);
		Maillage<float,vector> N(Point<float>(2,3), Point<float>(5,6), Point<float>(3,8), Point<float>(0,5), 2*m, n);
		M.fusionner(N);
	}


	return EXIT_SUCCESS;
}
