//Nikunj Pradhan
// 18261640
// npgzx
// 11.7.2023
// 303
// File: Bank Account Header
// This is the main header file of Lab11
#ifndef BANKACCOUNT_H
#define BANKACCOUNT_H
#include <string>

struct BankAccount{
std::string name, CustomerID;
int age;
double Accountbalance;
};
//Description:This function adds the amount to the accountbalance of the struct
//Pre:The structure and the amount added
//Post: The structure is returned and a new account balance
BankAccount operator+(const BankAccount& account, double amount);
//Description:This function subtracts the amount to the accountbalance of the struct
//Pre:The structure and the amount subtracted
//Post: The structure is returned and a new account balance
BankAccount operator-(const BankAccount& account, double amount);
//Description:This function displays all the data within the struct
//Pre:The structure is the only condtion
//Post: The output of the all the data is printed
std::ostream& operator<<(std::ostream& os, const BankAccount& account);
//Description:This function finds the sum of all the accountbalances
//Pre:An array of all the structs and the size of the the array
//Post: A double of the sums of each struct's account balance
double calculateTotalBalance(BankAccount accounts[], int size);

#endif
