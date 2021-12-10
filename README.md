************************************
  Object Oriented Programming in C++
************************************

-------------
    Goal:
-------------
  • Learn to apply the concepts of Operator Overloading and friend functions.
  • To make yourself comfortable with Templates

  Description:
  In this program, I have developed the class definition and behavior for Matrices. 
  I have implement the following operations on matrices.
  1. Addition ( + )
  2. Subtraction (‐ )
  3. Multiplication ( * )
  4. Post and pre Increment ( ++ )
  5. Post and pre Decrement ( ‐‐ )
  6. Transpose ( ~ )
  7. Positive exponential ( ^ )
  8. Output ( << )

  To make it interesting, I have overloaded operators such that above operations can be conducted on matrices. 
  For each of the operation, operator that performs overloading on is shown in parenthesis. 
  For example:
  -for matrix addition, overloading ‘+’ operator.

  Furthermore:
  -Define Extraction/Output, Increment and Decrement operations 
	as friend functions so that we do not have to create an object
	
  Operations 1, 2, and 3 correspond to standard matrix addition, subtraction and multiplication.
  Operation 4, Increment (++) operation on matrix increments each element of the matrix by 1. 
  Similarly, Operation 5, decrement (--) operator decrements the value of each element by 1. 
  Operator 6, Transpore (~) operator swaps values of rows[i] and columns[i] with each other in the 
  given Matrix. Positive Exponential (^) operator uses pow function to calculate the power (from user input) 
  on the values of a given matrix. Stream output operator (<<) prints the matrix on to standard output (screen).

  For simplicity:
  -Restrict ourselves to square matrices
	i.e., matrices in which number of rows and columns are same. 
	
  Furthermore:
  -Only deal with integer values 
	i.e., each element of the matrix can be either positive or negative integers only (including 0).
	
  Input Format:
  Read the matrices from a file provided as a command-line argument. 

  First line of input file contains the dimension of the matrix (d). 
  First line is followed by d lines of values. 
  Each line corresponds to one row of the matrix and hence 
  each row will have d integers.

  Operation that to perform will be given in a separate line 
  which is in the form op <num>.
  num is one of 1-8. 
  Consider the numbers given in first section as the numbers for each operation.

  For example:
  -op 1 corresponds to matrix addition and 
  -op 4 corresponds to Increment operation. 

  Second matrix, if needed, is followed by operation line.

  Few examples of input:
  Input1.txt
  ----------
  3
  1 2 3
  4 5 6
  7 8 9
  op 1
  10 11 12
  13 14 15
  16 17 18

  Input2.txt
  ----------
  4
  10 11 12 13
  14 15 16 17
  18 19 20 21
  22 23 24 25
  op 5
  (for operation 5 i.e., for increment we do not need second matrix)

  Input3.txt
  ----------
  2
  1 3
  4 6
  op 3
  2 4
  4 7

  Once the required operation is performed, 
  result matrix is printed onto output screen. 
  (Use << operator to print the matrix.)

  --------------------------
  Example Execution sequence
  --------------------------
  >> g++ matrix.cpp
  >> ./a.out sub.txt 
  <output>
  11 13 15
  17 19 21
  23 25 27

  You can implement in whatever way you want 
  as long as you adhere to the requirements ofoperator overloading, 
  friend functions and input format.

  ------
  Build
  ------
  compile = $ make
  clean =   $ make clean
  run =     $ ./matrix add.txt			//change accordingly
	

  ------------------
  SAMPLE INPUT FILES
  ------------------
  add.txt - Demonstrate addition of matrices
  sub.txt - Demonstrate subtraction of matrices
  mul.txt - Demonstrate multiplication of matrices
  inc.txt - Demonstrate incrementation of a matrix
  dec.txt - Demonstrate decrementation of a matrix
  tra.txt - Demonstrate transpose of a matrix
  pos.txt - Demonstrate positive exponential of a matrix
  out.txt - Demonstrate output operator overloading by printing a matrix