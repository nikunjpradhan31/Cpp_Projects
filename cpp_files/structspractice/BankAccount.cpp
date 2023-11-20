// Nikunj Pradhan
// 18261640
// npgzx
// 303
// 11.7.2023
// File: BankAccount.cpp
// Purpose: This is the file that contains all of the function definitions
#include "BankAccount.h"
#include <iostream>
BankAccount operator+ (const BankAccount& account, double amount)
{
  BankAccount temp = account;
  temp.Accountbalance+=amount;
  return temp;
}

BankAccount operator- (const BankAccount& account, double amount)
{
  BankAccount temp = account;
  if(temp.Accountbalance - amount < 0)
    std::cout<<"Insufficient Balance"<<std::endl;
  else
    temp.Accountbalance-=amount;
  return temp;
}
std::ostream& operator<<(std::ostream& os, const BankAccount& account)
{
  os<<"Name: "<<account.name<<"\nAge: "<<account.age<<"\nCustomerID: "<<account.CustomerID<<"\nAccount Balance: $"<<account.Accountbalance<<std::endl;
  return os;
}
double calculateTotalBalance(BankAccount accounts[], int size)
{
  double sum = 0.0;
  for(int x=0;x<size;x++)
  {
  sum += accounts[x].Accountbalance;
  }
  return sum;
}
