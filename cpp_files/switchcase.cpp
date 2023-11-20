// Nikunj Pradhan
// 18261640
// 303
// 10.10.2023
// lab7.cpp
// Create a simulated bank account

#include <iostream>
using namespace std;

  float balance = 1000;
  void displayBalance();
  void performTransaction(bool choice,float amount);
  void withdraw(float amount);
  void deposit(float amount);
  void withdrawLoan(float amount);

int main(){
  int new_int, action;
  float new_amount;

  cout<<"\nIntialize balance 0-->No / 1-->Yes"<<endl;
  cin>>new_int;//Allows user to enter there own balance

  if(new_int == 1){
   cout<<"\nEnter Amount: $";
   cin>>balance;
  }

  do{

   cout<<"\n1. Display Balance\n2. Deposit\n3. Withdraw\n4. Quit";
   cout<<"\nEnter your choice: ";
   cin>>action;//do while loop that runs until the user wants to quit

   switch(action){//switch case that withdraws or deposits whatever the user wants
    case 1:
     displayBalance();
     break;
    case 2:
     cout<<"Enter amount: $";
     cin>>new_amount;
     cout<<new_amount<< " dolllars has been depostited"<<endl;
     performTransaction(true,new_amount);
     break;
    case 3:
     cout<<"Enter amount: $";
     cin>>new_amount;
     if(new_amount > balance){
      cout<<"Insufficient funds. Unable to withdraw $"<<new_amount;
      withdrawLoan(new_amount);
     }
     else{
      cout<<new_amount<< " dollars has been withdrawn"<<endl;
      performTransaction(false,new_amount); 
     }
     break;
    default:
     break;
  }

  cout<<"Your current balance is $"<<balance<<"\n";

  } while(action != 4);
  cout<<"Exiting Program. Thank you!"<<endl;
  return 0;
}

  void displayBalance(){
   cout<<"Your Balance is " << balance<<endl;
  }

  void performTransaction(bool choice,float amount ){
   if(choice)
    deposit(amount);
   else
    withdraw(amount);
  }

  void deposit(float amount){
   balance += amount;
  }
  void withdraw(float amount){
   balance -= amount;
  }

  void withdrawLoan(float amount){//gives the user a loan to pay and resets the value of the balance of ten
  float neg_amount = amount - balance;
  float interest, year;
  cout<<"\nEnter an interest rate ";
  cin>>interest;
  cout<<"\nEnter a year amount ";
  cin>>year; 
  float si = (interest*year*neg_amount)/100+ 10;//the interes that is owed
  balance = 10;
  cout<<"\nMoney to be withdrawn "<<neg_amount<<"\nThe rate of interest is "<<interest<<"% and the time to rturn the amount is "<<year<<"years.\nAmount to be returned to the bank is "<<neg_amount +si<<"\n$"<<amount<<" has been withdrawn.\nYour current balance is "<<balance<<endl;
  
  }
