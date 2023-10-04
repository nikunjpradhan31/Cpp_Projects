//Programmer: Nikunj Pradhan
// Date: 9/19/2023
// File: Lab4.cpp
// Purpose: learning if else branching statements, loops, relational operators, and logical operator

#include <iostream>
using namespace std;

int main()
{
int num,sum,last_digit, var;
cout<<"\nEnter a number: ";
cin>>num;
cout<<"\nDivisors are: ";
var = 1;
sum = 0;
while(var<num){
if(num%var==0)
{
cout<<var<<" ";
sum += var;
}
var++;
}
cout<<endl;
if(sum == num){
cout<<"\n"<<num<<" is a perfect number"<<endl;
}
else{
cout<<"\n"<<num<<" is not a perfect number"<<endl;
}
last_digit = num%10;
cout<<"\nResultant value after adding 5 to "<<last_digit<<" is: "<<last_digit+5<<endl;
last_digit+=5;
if(last_digit%2==0){
cout<<"\n"<<last_digit<<" is an even value\n"<<endl;
}
else
{
cout<<"\n"<<last_digit<<" is an odd value\n"<<endl;
}
return 0;
}
