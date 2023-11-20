// Nikunj Pradhan
// 18261640
// npgzx
// 303
// 10.31.2023
// header.h
// Header for lab10 files and compliation
#ifndef HEADER_H
#define HEADER_H

//Description: This number finds sums each of the digits to the power of three and if it is equal to the orginal number then it is a armstrong number
//Pre:An integer is inputted
//Post:If the number inputted is an armstrong number then it is return as true, else it is false
bool isArmstrong(int num);

//Description: adds two inputs of any data types
//Pre:two inputs of any type
//Post: returns the sum of two inputs
template<typename T>
T add(T a, T b);
//Description: subtracts two inputs of any data types 
//Pre: two inputs of any type
//Post: returns the differnce of two inputs
template<typename T>
T substract(T a, T b);
//Description: divides a by b of any data types
//Pre: two inputs of any type(the second input b, should not be 0)
//Post: returns the division of two inputs and if the divisor is 0 then it returns zero
template<typename T>
T divide(T a, T b);

//Description: multiply two inputs of any data types
//Pre: two inputs of any type
//Post: returns the product of two inputs
template<typename T>
T multiply(T a, T b);

#endif

