// Programmer: Nikunj Pradhan
// Student ID: 18261640
// Section 303
// Date: 10.17.2023
// Files: lab8.cpp
// Purpose: Create a customer ID and do a transaction

#include <iostream>
#include <ctime>
#include <string>
#include <cstdlib>
using namespace std;

//declaring functions
string GenerateCustomerId();
void Greet(string customerID);
void swapPrice(float & price1, float & price2);
float totalBill(float price1,float price2, float taxPercentage);


int main()//main function hosts other functions that generate the customerID, gathers the items and price, swaps the prices, and then get the tax and the total bill
{//main
  string item1, item2;
  float total, price1, price2, tax;
  string customer_ID = GenerateCustomerId();
  Greet(customer_ID);
  cout<<"Enter the name of the first item: ";
  cin>>item1;
  cout<<"Enter the price of the first item: ";
  cin>>price1;
  cout<<"Enter the name of the second item: ";
  cin>>item2;
  cout<<"Enter the price of the second item: ";
  cin>>price2;
  swapPrice(price1,price2);
  cout<<"Tax %: ";
  cin>>tax;
  cout<<"Item 1: "<<item1<<" Price 1: $"<<price1<<"\nItem 2: "<<item2<<" Price 2: $"<<price2<<endl;
  total =  totalBill(price1,price2,tax);
  cout<<"Total Bill: $ "<<total<<endl;
  return 0;
}//main

string GenerateCustomerId()
{
  //This function creates a user ID using the random function
  //Pre: None
  //Post: returns the string random number plus "C"
  srand(time(NULL));
  int custID = (rand()%(99)) + 100;
  return "C" + to_string( custID);
  //return "C" + static_cast<string>(custID);
}

void Greet(string customerId)
{
  //This function greets the user
  //Pre: Takes the customer ID string
  //Post: Does not return anything but greets the user on the terminal
 cout<<"\nWelcome customer "<<customerId<<"!"<<endl;
}

void swapPrice(float & price1,float & price2)
{
 //This function swaps the two prices
 //Pre: Is given the float price1 and price2
 //Post: Swtiches the values of price1 and price2 
  float temp = price1;
  price1 = price2;
  price2 = temp;
}

float totalBill(float price1,float price2,float taxPercentage)
{
  //This function finds the tax of the price, then finds the total bill
  //Pre: the float price1, price2, and taxPercentage are given for the calculations of the bill
  //Post: This function returns the tax percentage of the bill + the price making the total
  float tax = (taxPercentage/100) * (price1 + price2);
  float total = tax + price1 + price2;
  return total;
}
