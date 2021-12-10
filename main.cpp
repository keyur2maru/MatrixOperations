/**
    CSCI-222 Lab 3: Matrix Operations & Operator Overloading
    @main.cpp
    @author Keyur Maru
    @version 1.0 12/09/21
*/
#include "matrix.h"

/* void parseFile:
 * Read and Parse .txt file provided from Program Argument (argv[1])
 * Store parsed data into one or two (depending on the input txt file) 1-D vector passed as a reference to the function
 */
void parseFile(char
               const * v, std::vector < int > & a, std::vector < int > & b, int & size, int & operation) {
    std::fstream fin;
    int currentInt = 0; //Keep track of current Int in the stream
    fin.open(v);
    if (fin.fail()) { //Display error message if file not found
        std::cout << "Couldn't read the file!" << std::endl;
        exit(1);
    }
    fin >> size; //Store size obtained from stream into referenced size var
    for (int i = 0; i < size * size; i++) { //Loop through stream to initialize and populate Matrix 1
        fin >> currentInt;
        a.push_back(currentInt);
    }
    fin.ignore(4); //Skip spaces and Ignore OP <num> for the next Matrix
    fin >> operation; //Save requested OP into referenced operation var
    if (operation < 4) { //Run following loop only if operation < 4
        for (int i = 0; i < size * size; i++) { //Loop through rest of the stream to initialize and populate Matrix 2
            fin >> currentInt;
            b.push_back(currentInt);
        }
    }
}

int main(int argc, char * argv[]) {
    (void) argc; //Make clang-tidy happy
    int size = 0;
    int operation = 0;
    std::vector < int > mat1; //1-D int vector to store Matrix 1 for parseFile func
    std::vector < int > mat2; //1-D int vector to store Matrix 2 for parseFile func
    parseFile(argv[1], mat1, mat2, size, operation); //Send .txt to parsing

    Matrix < int > m1(mat1, size); //Create an object of class Matrix to store Matrix 1 (vector of vectors)
    Matrix < int > m2(mat2, size); //Create an object of class Matrix to store Matrix 2 (vector of vectors)

    m1.populateMatrix(); //Populate values of Matrix 1

    std::cout << "Parsed Input Matrix 1: " << std::endl;
    std::cout << m1;
    if (operation < 4) { //Run the following statement only if OP < 4
        m2.populateMatrix(); //Populate values of Matrix 2
        std::cout << "Parsed Input Matrix 2: " << std::endl;
        std::cout << m2;
    }
    std::cout << "Requested Operation: " << operation << std::endl;
    Matrix < int > m3; //Create another object of Matrix class to store resultant object from overloaded operators
    std::cout << "Result Matrix: " << std::endl;
    switch (operation) {
        case 1:
            m3 = m1 + m2;
            std::cout << m3 << std::endl;
            break;
        case 2:
            m3 = m1 - m2;
            std::cout << m3 << std::endl;
            break;
        case 3:
            m3 = m1 * m2;
            std::cout << m3 << std::endl;
            break;
        case 4:
            m3 = m1++;
            std::cout << "Post Increment" << std::endl;
            std::cout << m3 << std::endl;
            m3 = ++m1;
            std::cout << "Pre Increment" << std::endl;
            std::cout << m3 << std::endl;
            break;
        case 5:
            m3 = m1--;
            std::cout << "Post Decrement" << std::endl;
            std::cout << m3;
            m3 = --m1;
            std::cout << "Pre Decrement" << std::endl;
            std::cout << m3;
            break;
        case 6:
            m3 = ~m1;
            std::cout << m3 << std::endl;
            break;
        case 7:
            std::cout << "Positive Exponential(^)\nPlease Enter Power: " << std::endl;
            std::cin >> size;
            m3 = m1 ^ size;
            std::cout << m3;
            break;
        case 8:
            std::cout << m1;
            break;
        default:
            std::cout << "Failed to read operation" << std::endl;
    }
}