/**
    CSCI-222 Lab 3: Matrix Operations & Operator Overloading
    @matrix.h
    @author Keyur Maru
    @version 1.0 12/09/21
*/
#ifndef MATRIX_H
#define MATRIX_H

#include <iostream>

#include <vector>
#include <math.h>
#include <fstream>

template < typename T >
class Matrix {
public:
    Matrix(); //Default constructor
    Matrix(const std::vector < int > & v, int size); //Parameterized constructor
    T initMatrix(); //Prototype initMatrix()
    T populateMatrix(); //Prototype populateMatrix()
    Matrix < T > operator + (Matrix < int > & m); //Prototype operator+ overloading
    Matrix < T > operator - (Matrix < int > & m); //Prototype operator- overloading
    Matrix < T > operator * (Matrix < int > & m); //Prototype operator* overloading
    Matrix < T > operator~(); //Prototype operator~ overloading
    Matrix < T > operator ^ (int power); //Prototype operator^ overloading
    friend std::ostream & operator << (std::ostream & os, Matrix < int > & m); //Prototype operator<< overloading
    friend Matrix < T > operator++(Matrix < int > & m); //Prototype operator++ overloading
    friend Matrix < T > operator++(Matrix < int > & m, int);
    friend Matrix < T > operator--(Matrix < int > & m); //Prototype operator-- overloading
    friend Matrix < T > operator--(Matrix < int > & m, int);

private:
    int size;
    std::vector < std::vector < T >> matrix_r;
    std::vector < T > matrix_c;
    std::vector < T > temp;
};
#endif //MATRIX_H