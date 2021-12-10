/**
    CSCI-222 Lab 3: Matrix Operations & Operator Overloading
    @matrix.cpp
    @author Keyur Maru
    @version 1.0 12/09/21
*/
#include "matrix.h"  //include header file

template < typename T > //Default constructor to initialize an instance of matrix class without any parameters
Matrix < T > ::Matrix() =
default;

template < typename T >
Matrix < T > ::Matrix(const std::vector < int > & v, int size) { //Parameterized constructor for creating an instance of matrix class and store referenced 1-D vector and size
    this -> size = size;
    temp = v; //Temporary save referenced 1-D vector to temp
}

/* initMatrix()
 * Resize and return vector of vectors to the requested size
 */
template < typename T >
T Matrix < T > ::initMatrix() { //Initialize Matrix (vector of vectors) by resizing it according to our size
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            matrix_c.push_back(i);
        }
        matrix_r.push_back(matrix_c);
    }
    return 0;
}

/* populateMatrix()
 * Put in values to the vector of vectors using 1-D vector provided from the constructor
 */
template < typename T >
T Matrix < T > ::populateMatrix() { //Populate values into Matrix
    int counter = 0;
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            matrix_c.push_back(temp[counter]); //First store columns
            counter++;
        }
        matrix_r.push_back(matrix_c); //Store columns into their respective rows
        matrix_c.clear();
    }
    return 0;
}

template < typename T >
Matrix < T > Matrix < T > ::operator + (Matrix < int > & m) { //Overloaded + operator
    Matrix resultMatrix(temp, size); //Create temporary instance of class Matrix to return result
    resultMatrix.initMatrix(); //Resize vector according to size
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            resultMatrix.matrix_r[i][j] = matrix_r[i][j] + m.matrix_r[i][j]; //Store new vector into object resultMatrix
        }
    }
    return resultMatrix; //Return new object with resultant vector in it
}

template < typename T >
Matrix < T > Matrix < T > ::operator - (Matrix < int > & m) { //Overloaded subtraction (-) operator
    Matrix resultMatrix(temp, size); //Create temporary instance of class Matrix to return result
    resultMatrix.initMatrix(); //Resize vector to fit in all the values
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            resultMatrix.matrix_r[i][j] = matrix_r[i][j] - m.matrix_r[i][j];
        }
    }
    return resultMatrix;
}

template < typename T >
Matrix < T > Matrix < T > ::operator * (Matrix < int > & m) { //Overloaded multiplication (*) operator
    Matrix resultMatrix(temp, size); //Create temporary instance of class Matrix to return result
    resultMatrix.initMatrix(); //Resize vector to fit in all the values
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            resultMatrix.matrix_r[i][j] = matrix_r[i][j] * m.matrix_r[i][j];
        }
    }
    return resultMatrix;
}

Matrix < int > operator++(Matrix < int > & m, int) { //Overloaded post-increment (++) operator
    for (int i = 0; i < m.matrix_r.size(); i++) {
        for (int j = 0; j < m.matrix_r.size(); j++) {
            m.matrix_r[i][j] = m.matrix_r[i][j]++;
        }
    }
    return m;
}

Matrix < int > operator++(Matrix < int > & m) { //Overloaded pre-increment (++) operator
    for (int i = 0; i < m.matrix_r.size(); i++) {
        for (int j = 0; j < m.matrix_r.size(); j++) {
            m.matrix_r[i][j] = m.matrix_r[i][j]++;
        }
    }
    return m;
}

Matrix < int > operator--(Matrix < int > & m, int) { //Overloaded post-decrement (--) operator
    for (int i = 0; i < m.matrix_r.size(); i++) {
        for (int j = 0; j < m.matrix_r.size(); j++) {
            m.matrix_r[i][j] = m.matrix_r[i][j]--;
        }
    }
    return m;
}

Matrix < int > operator--(Matrix < int > & m) { //Overloaded pre-decrement (--) operator
    for (int i = 0; i < m.matrix_r.size(); i++) {
        for (int j = 0; j < m.matrix_r.size(); j++) {
            m.matrix_r[i][j] = m.matrix_r[i][j]--;
        }
    }
    return m;
}

template < typename T >
Matrix < T > Matrix < T > ::operator~() { //Overloaded transpose(~) operator
    Matrix m(temp, size); //Create temporary instance of class Matrix to return result
    m.initMatrix(); //Resize vector to fit in all the values
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            m.matrix_r[i][j] = matrix_r[j][i]; //Switch values of i and j
        }
    }
    return m;
}

template < typename T >
Matrix < T > Matrix < T > ::operator ^ (int power) { //Overloaded exponential (^) operator
    Matrix m(temp, size); //Create temporary instance of class Matrix to return result
    m.initMatrix(); //Resize vector to fit in all the values
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            m.matrix_r[i][j] = pow(matrix_r[i][j], power); //Use pow func to get power
        }
    }
    return m;
}

std::ostream & operator << (std::ostream & os, Matrix < int > & m) { //Overloaded Extraction (<<) Operator
    for (int i = 0; i < m.matrix_r.size(); i++) {
        for (int j = 0; j < m.matrix_r.size(); j++) {
            os << m.matrix_r[i][j] << " ";
        }
        os << std::endl;
    }
    return os;
}
template class Matrix < int > ; //resolve linker error