/// Course:  CS213 - Programming II  - 2018
/// Title:   Assignment 2 - Task 1 - Problem 0
/// Program: CS213-2018-A2 - T1 - P0
/// Author:  Dr. Mohammad El-Ramly
/// Date:    10 August 2018
/* programmers: Ahmed Sayed Mansour   20170022
				Eslam Saleh Mohamed   20170046
				Eslam Mohamed Mahmoud 20170049
*/
/// last edit : 26/10/2018
/// Version: 1.0

#pragma once
#include <iostream>
#include <iomanip>
#include <cassert>

using namespace std;

class matrix
{
private:
	int** data;       // Pointer to 2-D array that will simulate matrix
	int row, col;
public:

	//A constructor that creats a matrix non intializted
	matrix();

	// Constructor that creat a matrix from an array
	matrix(int row, int col, int num[]);

	// Constructor that creat an empty matrix
	matrix(int row, int col);

	//Two functions to the rows aand columons of a matrix
	int getrow();
	int getcol();

	//iostream for input and output
	friend ostream& operator<< (ostream& out, const matrix& mat);

	// a copy constructor
	matrix(const matrix& old);

	// A function to get the sum of two matrices
	friend matrix operator+( matrix  & mat1,  matrix  & mat2);

	// A function to remove the value of another matrix from it
	friend matrix operator-( matrix &mat1,  matrix &mat2);

	//  A function to produce two matrices
	friend matrix operator*(matrix &mat1, matrix &mat2);

	// A function to add a value to A matrix
	friend  matrix operator+(matrix &mat1, int scalar);

	//A matrix to remove a value from a matrix
	friend matrix operator-(matrix &mat1, int scalar);

	// A function to produce a value in  a matrix
	friend matrix operator*(matrix mat1, int scalar);

	//postfix and prefix increment and decrement operators

	// Increment Matrix Elements By 1
	matrix& operator++ ();
	matrix& operator++ (int);

	// Decrement Matrix Elements By 1
	matrix& operator-- ();
	matrix& operator-- (int);

	// Append Second Matrix Elements to the First One
	friend matrix operator+= (matrix& mat1, matrix &mat2);

	// Substract Second Matrix Elements from the First One
	friend matrix operator-= (matrix& mat1, matrix& mat2);

	//Increase Matrix Elements with Given Constant Value
	friend matrix operator+= (matrix& mat1, int scalar);

	//Decrease Matrix Elements by Given Constant Value
	friend matrix operator-= (matrix& mat1, int scalar);
	
	//Input Function
	friend istream& operator>> (istream& in, matrix& mat);

	//check if two matrices are equal and return 1 if equal and 0 if not
	friend bool operator== (matrix& mat1, matrix& mat2);

	//check if two matrices are equal and return 0 if equal and 1 if not
	friend bool operator!= (matrix& mat1, matrix& mat2);

	// check if number of rows equal the number of cols and return 1 if equal and return 0 if not
	bool isSquare();

	// check if the value of matrix [i][j] equal the value matrix [j][i] and return 1 if equal and return 0 if not
	bool isSymetric();

	// check if all values of the main diagonal equal 1's and return 1 if equal and return 0 if not
	bool isIdentity();

	// A function to rotate a matrix;
	friend matrix& transpose(matrix& mat);

	virtual ~matrix();
};

