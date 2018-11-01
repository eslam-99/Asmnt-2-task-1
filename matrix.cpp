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

#include "matrix.h"

//A constructor that creats a matrix non intializted
matrix::matrix() {}

// Constructor that creat a matrix from an array
matrix::matrix(int row, int col, int num[])
{
	this->row = row;
	this->col = col;
	data = new int*[row];

	for (int i = 0; i < row; i++)
		data[i] = new int[col];

	for (int i = 0; i < row; i++)
		for (int j = 0; j < col; j++)
			data[i][j] = num[i * col + j];
}

// Constructor that creat an empty matrix
matrix::matrix(int row, int col)
{
	this->row = row;
	this->col = col;
	data = new int*[row];
	for (int i = 0; i < row; i++)
		data[i] = new int[col];
}

//Two functions to the rows aand columons of a matrix
int matrix::getrow() { return row; }
int matrix::getcol() { return col; }

//iostream for output
ostream& operator<< (ostream& out, const matrix& mat)
{
	for (int i = 0; i < mat.row; i++)
	{
		out << endl;
		for (int j = 0; j < mat.col; j++)
			out << mat.data[i][j] << "  ";
	}
	out << endl << endl;

	return out;
}


//A copy constructor
matrix::matrix(const matrix & old)
{
	this->col = old.col;
	this->row = old.row;
	this->data = new int*[row];

	for (int i = 0; i < row; i++)
		this->data[i] = new int[col];

	for (int i = 0; i < row; i++)
		for (int j = 0; j < col; j++)
			this->data[i][j] = old.data[i][j];
}


// A function to get the sum of two matrices
matrix operator+( matrix  & mat1, matrix  & mat2) 
{
	assert((mat1.row == mat2.row) && (mat1.col == mat2.col));	//to sure if rows and cols are equal

	matrix mat(mat1.row, mat2.col);				//setting number of rows and cols in object mat
	for (int i = 0; i < mat1.row; i++)
		for (int j = 0; j < mat2.col; j++)
			mat.data[i][j] = 0;                // initialize all values equal 0

	for (int i = 0; i < mat.row; i++)
	{
		for (int j = 0; j < mat.col; j++)
		{
			mat.data[i][j] = (mat1.data[i][j] + mat2.data[i][j]);    //get the sum(all values mat1+ all values in mat2) and put it in mat
		}
	}
	return mat;
}

// A function to remove the value of another matrix from it
matrix operator-(matrix &mat1, matrix &mat2)
{

	assert((mat1.row == mat2.row) && (mat1.col == mat2.col));   //to sure if rows and cols are equal
	matrix mat(mat1.row,mat2.col);

	for (int i = 0; i < mat1.row; i++)
		for (int j = 0; j < mat2.col; j++)
			mat.data[i][j] = 0;                 //initialize all values to 0


	for (int i = 0; i < mat.row; i++)
	{
		for (int j = 0; j < mat.col; j++)
		{
			mat.data[i][j] = (mat1.data[i][j] - mat2.data[i][j]);    //remove values
		}
	}
	return mat;
}

//  A function to produce two matrices
matrix operator*(matrix &mat1, matrix &mat2)
{
	assert((mat1.col == mat2.row));        //to sure if rows and cols are equal
	matrix mat(mat1.row, mat2.col);

	for (int i = 0; i < mat1.row; i++)
		for (int j = 0; j < mat2.col; j++)
			mat.data[i][j] = 0;         // initialize all values to 0

	for (int i = 0; i < mat1.row; i++)
		for (int j = 0; j < mat2.col; j++)
			for (int k = 0; k < mat1.col; k++)
			{
				mat.data[i][j] += mat1.data[i][k] * mat2.data[k][j];   //get the production
			}
	return mat;
}

// A function to add a value to A matrix
matrix operator+(matrix &mat1, int scalar)
{

	matrix mat(mat1.row, mat1.col);

	for (int i = 0; i < mat1.row; i++)
		for (int j = 0; j < mat1.col; j++)
			mat.data[i][j] = 0;    //initialize all values to 0


	for (int i = 0; i < mat.row; i++)
	{
		for (int j = 0; j < mat.col; j++)
		{
			mat.data[i][j] = (mat1.data[i][j] + scalar);   //get the sum
		}
	}
	return mat;
}

//A matrix to remove a value from a matrix
matrix operator-(matrix &mat1, int scalar)
{

	matrix mat(mat1.row, mat1.col);

	for (int i = 0; i < mat1.row; i++)
		for (int j = 0; j < mat1.col; j++)
			mat.data[i][j] = 0;          //initialize all values to 0


	for (int i = 0; i < mat.row; i++)
	{
		for (int j = 0; j < mat.col; j++)
		{
			mat.data[i][j] = (mat1.data[i][j] - scalar);  //the equation
		}
	}
	return mat;
}

// A function to produce a value in  a matrix
matrix operator*(matrix mat1, int scalar)
{

	matrix mat(mat1.row, mat1.col);

	for (int i = 0; i < mat1.row; i++)
		for (int j = 0; j < mat1.col; j++)
			mat.data[i][j] = 0;            //initialize all values to 0


	for (int i = 0; i < mat.row; i++)
	{
		for (int j = 0; j < mat.col; j++)
		{
			mat.data[i][j] = (mat1.data[i][j] * scalar);    //The equation
		}
	}
	return mat;
}

//postfix and prefix increment and decrement operators
matrix& matrix::operator++ () 
{
	*this = *this + 1;
	return *this;
}
matrix& matrix::operator++ (int)
{
	matrix tmp(*this);
	++(*this);
	return tmp;
}
matrix& matrix::operator-- ()
{
	*this = *this - 1;
	return *this;
}
matrix& matrix::operator-- (int) 
{
	matrix tmp(*this);
	--(*this);
	return tmp;
}

// Append Second Matrix Elements to the First One
matrix operator+= (matrix& mat1, matrix& mat2)
{
	assert((mat1.row == mat2.row) && (mat1.col == mat2.col)); //Check if 2 matrices have same dimensions

	for (int i = 0; i < mat1.row; i++)
		for (int j = 0; j < mat2.col; j++)
			mat1.data[i][j] += mat2.data[i][j]; // loop and add second matrix element to the first one

	return mat1;
}

// Substract Second Matrix Elements from the First One
matrix operator-= (matrix& mat1, matrix& mat2)
{
	assert((mat1.row == mat2.row) && (mat1.col == mat2.col)); //Check if 2 matrices have same dimensions

	for (int i = 0; i < mat1.row; i++)
		for (int j = 0; j < mat2.col; j++)
			mat1.data[i][j] -= mat2.data[i][j]; // loop and remove second matrix element to the first one

	return mat1;
}

//Increase Matrix Elements with Given Constant Value
matrix operator+= (matrix& mat1, int scalar)
{
	
	for (int i = 0; i < mat1.row; i++)
		for (int j = 0; j < mat1.col; j++)
			mat1.data[i][j] += scalar; // add the constant value to the temp matrix

	return mat1;
}

//Decrease Matrix Elements by Given Constant Value
matrix operator-= (matrix& mat1, int scalar)
{
	
	for (int i = 0; i < mat1.row; i++)
		for (int j = 0; j < mat1.col; j++)
			mat1.data[i][j] -= scalar; // remove the constant value to the temp matrix

	return mat1;
}

//Input Function
istream& operator>> (istream& in, matrix& mat)
{
	cin >> mat.row >> mat.col;  // Take rows and cols from the user

	mat.data = new int*[mat.row];

	for (int i = 0; i < mat.row; i++)
		mat.data[i] = new int[mat.col];

	for (int i = 0; i < mat.row; i++)
		for (int j = 0; j < mat.col; j++)
			in >> mat.data[i][j]; // Enter Elements Gradually

	return in;
}

//check if two matrices are equal and return 1 if equal and 0 if not
bool operator== (matrix& mat1, matrix& mat2)
{
	if ((mat1.row != mat2.row) || (mat1.col != mat2.col))    // the same as assert
	{
		return false;
	}
	for (int i = 0; i < mat1.row; i++)
	{
		for (int j = 0; j < mat1.col; j++)
		{
			if (mat1.data[i][j] != mat2.data[i][j])
				return false;
		}
	}
	return true;
}

//check if two matrices are equal and return 0 if equal and 1 if not
bool operator!= (matrix& mat1, matrix& mat2)
{
	if ((mat1.row != mat2.row) || (mat1.col != mat2.col))
	{
		return true;
	}
	for (int i = 0; i < mat1.row; i++)
	{
		for (int j = 0; j < mat1.col; j++)
		{
			if (mat1.data[i][j] != mat2.data[i][j])
				return true;
		}
	}
	return false;
}

// check if number of rows equal the number of cols and return 1 if equal and return 0 if not
bool matrix::isSquare()
{
	if (row == col)
		return true;
	else
		return false;
}

// check if the value of matrix [i][j] equal the value matrix [j][i] and return 1 if equal and return 0 if not
bool matrix::isSymetric()
{
	if ((this->isSquare()) == false)
		return false;
	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < col; j++)
		{
			if (data[i][j] != data[j][i])  //check if they are equal
				return false;
		}
	}
	return true;
}

// check if all values of the main diagonal equal 1's and return 1 if equal and return 0 if not
bool matrix::isIdentity()
{
	if (this->isSquare() == false)
		return false;
	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < col; j++)
		{
			if (i == j)
			{
				if (data[i][j] != 1)    // check if all main diagonal values are equal to one
					return false;
			}
			else if (data[i][j] != 0)
				return false;
		}
	}
	return true;
}

// A function to rotate a matrix;
matrix& transpose(matrix& mat)
{
	matrix mat1(mat.col, mat.row);

	for (int i = 0; i < mat.row; i++)
		for (int j = 0; j < mat.col; j++)
			mat1.data[i][j] = mat.data[j][i];     //put all values in the rotated matrix
	
	for (int i = 0; i < mat.row; i++)
		for (int j = 0; j < mat.col; j++)
			mat.data[i][j] = mat1.data[i][j];

	return mat;
}

matrix::~matrix()
{
	
}
