/// Course:  CS213 - Programming II  - 2018
/// Title:   Assignment 2 - Task 1 - Problem 0
/// Program: CS213-2018-A1-T1-P0
/// Author:  Dr. Mohammad El-Ramly
/// Date:    10 August 2018
/* programmers: Ahmed Sayed Mansour   20170022
				Eslam Saleh Mohamed   20170046
				Eslam Mohamed Mahmoud 20170049
*/
/// last edit : 26/10/2018
/// Version: 1.0

#include <iostream>
#include "matrix.h"

using namespace std;

int main()
{
	int data1[] = { 1,2,3,4,5,6,7,8 };
	int data2[] = { 13,233,3,4,5,6 };
	int data3[] = { 10,100,10,100,10,100,10,100 };
	int data4[] = { 10,100,10,100,10,100,10,100 };

	matrix  mat1(4, 2, data1);
	matrix  mat2(2, 3, data2);
	matrix  mat3(4, 2, data3);
	matrix  mat4(2, 4, data4 );

	matrix  mat_temp_1(4, 2, data1);
	matrix  mat_temp_2(2, 3, data2 );
	matrix  mat_temp_3(4, 2, data3);


	// The next code will not work until you write the functions

	cout << "mat1 : " << endl;
	cout << mat1 << endl;

	cout << "mat2 : " << endl;
	cout << mat2 << endl;

	cout << "mat3 : " << endl;
	cout << mat3 << endl;

	cout << "mat4 : " << endl;
	cout << mat4 << endl;

	cout << "mat1 + mat3 : " << endl;
	cout << (mat1 + mat3) << endl << endl;

	cout << "mat3 + mat3 : " << endl;
	cout << (mat3 + mat3) << endl << endl;

	cout << "mat3 - mat1 : " << endl;
	cout << (mat3 - mat1) << endl << endl;

	cout << "mat1 * mat2 : " << endl;
	cout << (mat1 * mat2) << endl << endl;

	cout << "mat1 + 3 : " << endl;
	cout << (mat1 + 3) << endl << endl;

	cout << "mat1 - 3 : " << endl;
	cout << (mat1 - 3) << endl << endl;

	cout << "mat1 * 3 : " << endl;
	cout << (mat1 * 3) << endl << endl;

	++mat1;
	cout << "++mat1 : " << endl;
	cout << mat1 << endl;

	--mat1;
	cout << "--mat1 : " << endl;
	cout << mat1 << endl;

	mat1 += mat3;
	cout << "after  mat1 += mat3 : " << endl;
	cout << "mat1 : " << endl;
	cout << mat1 << endl;

	cout << "mat2 : " << endl;
	cout << mat2 << endl;

	cout << "mat3 : " << endl;
	cout << mat3 << endl;

	mat1 -= mat3;

	cout << "after  mat1-=mat3 : " << endl;
	cout << "mat1 : " << endl;
	cout << mat1 << endl;

	cout << "mat2 : " << endl;
	cout << mat2 << endl;

	cout << "mat3 : " << endl;
	cout << mat3 << endl;

	cout << "mat1 += 3 : " << endl;
	cout << (mat1 += 3) << endl << endl;

	cout << "mat1 -= 3 : " << endl;
	cout << (mat1 -= 3) << endl << endl;

	matrix matt;
	cout << "Enter H * W and Matrix : ";
	cin >> matt;

	cout << "Your  " << matt.getrow() << " * " << matt.getcol() << "  matrix is " << endl;
	cout << matt << endl << endl;

	cout << "mat1 == mat1 : " << endl;
	cout << (mat1 == mat1) << endl << endl;

	cout << "mat1 != mat3 : " << endl;
	cout << (mat1 != mat3) << endl << endl;

	matrix myMat;

	cout << "Enter H * W && Matrix to check if Square : " << endl;
	cin >> myMat;
	cout << "isSquare(myMat) : ";
	cout << myMat.isSquare() << endl << endl;

	cout << "Enter H * W && Matrix to check if Symetric : " << endl;
	cin >> myMat;
	cout << "isSymetric(myMat) : ";
	cout << myMat.isSymetric() << endl << endl;

	cout << "Enter H * W && Matrix to check if Identity : " << endl;
	cin >> myMat;
	cout << "isIdentity(myMat) : ";
	cout << myMat.isIdentity() << endl << endl;

	cout << "Enter H * W && Matrix to Transpose : " << endl;
	cin >> myMat;
	cout << "transposed Matrix : " << endl;
	cout << transpose(myMat) << endl << endl;


	// Add more examples of using matrix
	// .......

	system("pause");
}
