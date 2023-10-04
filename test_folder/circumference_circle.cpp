//Nikunj Pradhan
// 18261640
// CS1580 303
// 9/12/2023
// lab3.cpp
// Purpose: Write a porgram that takes a Radius as input from the user and calculates the following parameters

#include <iostream>

using namespace std;
const float PI = 3.14159;
int main()
{
int radius, lsb, area_mod;
float Circumference, Area;
char m = 'm';
cout<<"Enter the radius of the circle: ";
cin >> radius;
Circumference = 2*PI*radius; //Equation for Circumference 
cout<<"Circumference of the circle: "<< Circumference <<m<<endl;
lsb = static_cast<int>(Circumference)%10; //Changes Circumference to int and mod 10
cout<<"Least significant bit of circumference is: " <<lsb <<endl;
Area = PI*radius*radius;
cout<<"Area of the circle: " << Area<<m<<"^2"<<endl;
area_mod = Area -100; // Modified Area is -100 + 1 as an int
++area_mod;
cout<<"Area after modification: "<< area_mod<<endl;

return 0;
}
