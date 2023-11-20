// Nikunj Pradhan
// npgzx
// 18261640
// 10.31.2023
// 303
// File: calculater template functions for lab10
#include<iostream>
#include "Header.h"

template<typename T>
T add(T a, T b)
{
  static int count = 0;
  count++;
  std::cout<<"Addition: add() has been called: "<<count<<"Result is "<<a+b<<std::endl;
  return a + b;
}
template<typename T>
T subtract(T a, T b)
{
  std::cout<<"Subtraction: "<<a-b<<std::endl;
  return a-b;
}
template<typename T>
T divide(T a, T b)
{
  if(b == 0)
   {
   std::cout<<"Error, Division by zero is not possible"<<std::endl;
   return 0;
   }
  else{
   std::cout<<"Division: "<<a/b<<std::endl;
   return a/b;
  }
}
template<typename T>
T multiply(T a, T b)
{
  std::cout<<"Multiplcation: "<<a*b<<std::endl;
  return a*b;
}
