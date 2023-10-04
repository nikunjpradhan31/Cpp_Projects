// Programmer: Nikunj Pradhan  
// Date: 9/27/2023
// File: HW3.cpp
// Assignment: HW3
// Purpose: this file encrypts and decrypts files for Caeser Cipher
#include <iostream>
using namespace std;

int main(){
  int shift;
  char crypt, cont;
  string enter;
  do{ //nested do while loops to ask if the user wants to encode or decode a message and to have the user input a vaild shift range.
    cout<<"\nDo you want to encrypt or decrypt a message? (e/d) ";
    cin>>crypt;
    cout<<"\nEnter the message to be encoded: ";
    cin.ignore();
    getline(cin, enter);
    do{
      cout<<"\nEnter a shift value(0-200) ";
      cin>>shift;
    }while(shift > 200 || shift < 0);//The condition will only exit if the shift is betwenn 0-200 inclusively
    shift%=26;//In order to shift through the alphabet, we must mod 26, for each letter of the alphabet so that we know how much to shift by
    if(crypt == 'd'){
    for(unsigned int i = 0; i<enter.length();i++){
      char let = enter[i];
      if((let >=97 && let <= 122) || (let >=65 && let <= 90)){//Looks for only the letters of the alphabet, uppercase and lowercase
        if((let >=65 && let < 65 + shift) || (let >=97 && let < 97 + shift))//For each part of the OR statement the character has be either in the lowercase or uppercase range and to include the edge looping cases  we must add the shift number to A and a ASCII values 
          enter[i] = static_cast<char>(let + 26 - shift); //for edge cases we add 26 and subtract the shift
        else
          enter[i] = static_cast<char>(let - shift);
      }
      else 
        continue;  
    }
    cout<<"\nYour decrypting message: "<<enter;
    }
  else{
  for(unsigned int i = 0; i<enter.length();i++){
    char let = enter[i];
    if((let >=97 && let <= 122) || (let >=65 && let <= 90)){
      if((let <=122 && let > 122 - shift) || (let <=90 && let > 90 - shift))//For each part of the OR statement the character has be to either in lowercase or uppercase range and to include the looping edge cases we must subtracting the edge number from the ASCII values of z and Z
         enter[i] = static_cast<char>(let - 26 + shift); // for edges cases we subtract 26 and add the shift number
      else
         enter[i] = static_cast<char>(let + shift);
    }
    else 
      continue;  
  }
    cout<<"\nYour encoding messages is: "<<enter;
  }
    cout<<"\nWould you like to continue the program? (y/n) : ";
    cin>>cont;
  }while(cont == 'y');
  cout<<"\nThanks for using Oscar Academy of Magic Caesar Cipher Program\n\nKeep making magic"<<endl;
  return 0;
}
