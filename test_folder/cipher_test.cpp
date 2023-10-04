// Programmer: Nikunj Pradhan
// Student ID: 18261640
// Section: 303
// Date: 9/26/2023
// File: Lab5.cpp
// Purpose: Obtaining the sum of the ascii values within a string
#include<iostream>
using namespace std;
int main()
{
  string obj;
  int sum = 0;
  string symbol = "!@#$%^&*()";
  cout<<"\nEnter a String (use '.' to end): ";
  getline(cin,obj);
  for(unsigned int x = 0; x<obj.length(); x++)
  {
    if(obj[x] == '.')
     break;
    else if((obj[x] >=97 && obj[x] <= 122) || (obj[x] >=65 && obj[x] <= 90)){
     cout<<obj[x]<<":"<<static_cast<int>(obj[x])<<" ";
     sum += static_cast<char>(obj[x]);
    }
    else{
     continue;
    }
  }
  cout<<"\nThe sum of the ASCII values is in the string is: "<<sum<<endl;

  return 0;
}
