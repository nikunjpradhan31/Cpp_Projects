//Programmer: Nikunj Pradhan
// Student ID: 18261640
// Section: 303
// Date: 10.24.2023
// File: Lab9.cpp
// Purpose: Creating template functions and default parameters

#include <iostream>
using namespace std;

//Description:This function finds the max of three numbers
//Pre: Takes three template value
//Post: Returns the largest value
template <typename T>
T findMax(T a, T b, T c)
{
  T max;
  if(a > b && a > c)
  max = a;
  else if (b > a && b > c)
  max = b;
  else
  max = c;
  return max;
}

//Description:This function finds the min of three numbers
//Pre: Takes three template value
//Post: Returns the smallest value
template <typename T>
T findMin(T a ,T b, T c)
{
  T min;
  if(a < b && a < c)
  min = a;
  else if (b < a && b <  c)
  min = b;
  else
  min = c;
  return min;

}

//Description:This function adds all numbers from one to the input large value
//Pre: Takes in the largest value parameter
//Post: Returns the the sum of all numbers from one to the num value
template <typename T>
T calculateAlternateSum(T num)
{
T sum = 0;
for(T x = 1;x<=num;x+=2){
sum+=x;
}
return sum;
}

//Description:This function returns the exponent of the base and the exponent multipler
//Pre: The function always takes a int base, and has a default argument for the exponen
//Post: Returns the exponent of a number
int findPower(int base, const int exponent = 3);

//Description:This function multiplys two numbers to each other
//Pre: This function always has a double that is multplied by a int that is a default argument
//Post: Returns the the product of two numbers
double multiplyByConstant(double num, const int multiplier = 2);

int main()
{//main
  int inta, intb, intc, mult, expo;
  double a, b, c;
  cout<<"\nEnter the integer values (3): "<<endl;
  cin >> inta;
  cin >> intb;
  cin >> intc;
  int intmax = findMax(inta,intb,intc);
  int intmin = findMin(inta,intb,intc);
  cout<<"\nMinimun integer value: "<<intmin;
  cout<<"\nMaximum integer value: "<<intmax;
  cout<<"\nEnter the double values (3): ";
  cin >> a;
  cin >> b;
  cin >> c;
  double max = findMax(a,b,c);
  double min = findMin(a,b,c);
  cout<<"\nMinimun double value: "<<min;
  cout<<"\nMaximum double value: "<<max;
  cout<<"\nEnter the exponent value: ";
  cin>>expo;
  int powermax = findPower(intmax);
  cout<<"\nMaximum integer value: "<<intmax<<" raised to the constant power is: "<<powermax;
  int powermin = findPower(intmin,expo);
  cout<<"\nMinimum integer value "<<intmin<<" raised to the power"<<expo<<" is: "<<powermin;
  double multmax = multiplyByConstant(max);
  cout<<"\nEnter the multipler values: ";
  cin>>mult;
  double multmin = multiplyByConstant(min,mult);
  cout<<"\nMaximum double "<<max<<" after multiplication by a constant: "<<multmax;
  cout<<"\nMinimum double "<<min<<" after multiplication by a multiplier: "<<multmin;
  cout<<"\nSum of alternate values till maxInt "<<intmax<<" is: "<<calculateAlternateSum(intmax);
  cout<<"\nSum of alternate values till maxDouble "<<max<<" is: "<<calculateAlternateSum(max)<<endl;

  return 0;
}//main

int findPower(int base, const int exponent)
{
  int ans = 1;
  for(int x = 0; x<exponent;x++){
  ans*=base;
  }
  return ans;
}
double multiplyByConstant(double num, const int multiplier)
{
 return num * multiplier;
}
