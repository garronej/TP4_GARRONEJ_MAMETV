/*!
 * \file test.cpp
 * \brief Fichier de tests unitaires.
 * \author GARRONE Joseph, joseph.garrone@ensimag.grenoble-inp.fr
 * \version 0.1 */
#define EXIT_SUCCESS 0 
#include <iostream> //std::cout, std::cin 
#include <exception> //pour les exception
#include <cassert> //Pour les assert
#include <sstream>      // std::stringstream
#include <fstream> // Pour std::ofstream 


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
	stringstream ss;
	ss << Mv;
	assert(ss.str() == "0 0\n0 1\n1 0\n0 0\n\n1 1\n0 1\n1 0\n1 1\n\n"); ss.str("");
	cout << "PASS" << endl;

	ofstream ofile;
	ofile.open("./generated/1.dat");
	ofile << Mv;
	ofile.close();

	Maillage<float, list> Ml(10,10, Point<float>(0,0));
	ofile.open("./generated/2.dat");
	ofile << Ml;
	ofile.close();

	Point<double> P1;

	P1 = Point<double>(1,1);
	
	assert(P1.x() ==(double)1);
	assert(P1.y() == (double)1);
	cout << "PASS" << endl;

	Point<double> P2(1,1);

	assert(P1 == P2);
	cout << "PASS" << endl;

	Maillage<float, list> M1(10,10, Point<float>(0,0));
	Maillage<float, list> M2(10,10, Point<float>(11,1));
	M2.fusioner(M1);
	ofile.open("./generated/3.dat");
	ofile << M2;
	ofile.close();


	Maillage<double, list> M3(Point<double>(2,3), Point<double>(5,6), Point<double>(3,8), Point<double>(0,5), 2,3);
	ofile.open("./generated/4.dat");
	ofile << M3;
	ofile.close();


	///*Rotate*/
	//Maillage<double, list> M5(10,10, Point<double>(0,0));
	//M5.tourner((double)3.14, Point<double>(0,0));
	//ofile.open("./generated/5.dat");
	//ofile << M5;
	//ofile.close();

	/*Deplacer*/
	Maillage<double, list> M6(10,10, Point<double>(0,0));

	ofile.open("./generated/6prev.dat");
	ofile << M6;
	ofile.close();

	M6.deplacer(5,4);
	ofile.open("./generated/6.dat");
	ofile << M6;
	ofile.close();

	return EXIT_SUCCESS;
}
