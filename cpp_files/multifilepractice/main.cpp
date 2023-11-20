// Nikunj Pradhan
// 18261640
// npgzx
// 303
// 10.31.2023
// File: main.cpp
// Purpose: Main function that calls header file, armstrong, and calculator file

#include<iostream>
#include"Header.h"
#include"armstrong.cpp"
#include"Calculator.cpp"
using namespace std;
int main()
{
  int num1, num2, num3;
  float num4, num5;
  cout<<"Enter a number to check if its Armstrong: ";
  cin>> num1;
  bool armstrong = isArmstrong(num1);
  if(armstrong == true)
   cout<<num1<<" is a armstrong number"<<endl;
  else
   cout<<num1<<" is not a armstrong number"<<endl;
  cout<<"Lets start the calculation operation. Enter two Intgers numbers: ";
  cin>> num2;
  cin>> num3;
  add(num2,num3);
  subtract(num2,num3);
  multiply(num2,num3);
  divide(num2,num3);
  cout<<"Enter two decimal numbers: ";
  cin >> num4;
  cin >> num5;
  add(num4,num5);
  subtract(num4,num5);
  multiply(num4,num5);
  divide(num4,num5);
  cout<<"Calling add() on Intetgers 5 times"<<endl;
  for(int x = 0; x<5;x++)
    {
    cout<<"Enter another Integer pair numbers: ";
    cin>>num2;
    cin>>num3;
    add(num2,num3);
    }
  for(int x = 0; x<3;x++)
    {
    cout<<"Enter another decimal pair numbers: "<<endl;
    cin>>num4;
    cin>>num5;
    add(num4,num5);
    }

  return 0;
}
