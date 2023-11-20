// Nikunj Pradhan
// 1826160
// npgzx
// 11.7.2023
// 303
// File: main.cpp
// Purpose: main function that runs lab11

#include <iostream>
#include "BankAccount.h"

int main()
{
  int size = 4;
  double amount;
  BankAccount acc1, acc2, acc3, acc4;
  BankAccount arrayBank[size] = {acc1,acc2,acc3,acc4};
  acc1.name = "John Doe";
  acc1.age = 30;
  acc1.CustomerID = "C1001";
  acc1.Accountbalance = 1500;

  acc2.name = "Jane Smith";
  acc2.age = 25;
  acc2.CustomerID = "C1002";
  acc2.Accountbalance = 2000;

  acc3.name = "Mike Johnson";
  acc3.age = 35;
  acc3.CustomerID = "C1003";
  acc3.Accountbalance = 1800;

  acc4.name = "Emily Davis";
  acc4.age = 28;
  acc4.CustomerID = "C1004";
  acc4.Accountbalance = 2500;

  std::cout<<acc1<<std::endl;
  std::cout<<acc2<<std::endl;
  std::cout<<acc3<<std::endl;
  std::cout<<acc4<<std::endl;
  std::cout<<"Total sum of all accounts: $"<<acc1.Accountbalance+acc2.Accountbalance+acc3.Accountbalance+acc4.Accountbalance<<std::endl;

  // std::cout<<"Total sum of all accounts: $"<<calculateTotalBalance(arrayBank,4)<<std::endl;
  std::cout<<"Enter amount to deposit for customer: $";
  std::cin>>amount;
  acc1=acc1+amount;

 // std::cout<<"Enter amount to withdraw for customer: $";
 // std::cin>>amount;
 // acc1=acc1-amount;

  //std::cout<<"Enter amount to deposit for customer: $";
  //std:: cin>>amount;
  //acc2=acc2+amount;

  std::cout<<"Enter amount to withdraw for customer: $";
  std::cin>>amount;
  acc2=acc2-amount;

  std::cout<<"Enter amount to deposit for customer: $";
  std::cin>>amount;
  acc3=acc3+amount;

  //std::cout<<"Enter amount to withdraw for customer: $";
  //std::cin>>amount;
  //acc3=acc3-amount;

  //std::cout<<"Enter amount to deposit for customer: $";
  //std::cin>>amount;
  //acc4=acc4+amount;

  std::cout<<"Enter amount to withdraw for customer: $";
  std::cin>>amount;
  acc4=acc4-amount;

  std::cout<<acc1<<std::endl;
  std::cout<<acc2<<std::endl;
  std::cout<<acc3<<std::endl;
  std::cout<<acc4<<std::endl;
  //std::cout<<"Total sum of all accounts: $"<<calculateTotalBalance(arrayBank,4)<<std::endl;
  std::cout<<"Total sum of all accounts: $"<<acc1.Accountbalance+acc2.Accountbalance+acc3.Accountbalance+acc4.Accountbalance<<std::endl;
  return 0;
}
