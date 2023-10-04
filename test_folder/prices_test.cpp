//Programmer: Nikunj Pradhan
// Student ID: 18261640
// Section: 303
// Date: 9/5/23
// File: lab2.cpp
// Purpose: Calulates the final price of an item after applying for a discount

#include <iostream>
using namespace std;
int main()
{
int og_amount, tax;
float dis_percent, dis_amount;
double dis_price;

//Assigning Variables to Data Types
cout<<"Enter the orginal amount: $";
cin>>og_amount;
cout<<"Enter the discount percentage: ";
cin>>dis_percent;
cout<<"Enter the tax amount: $";
cin>>tax;

//Inputting User Data for the amounts
cout<<"Original Price: $"<<og_amount<<endl<<"Discount Percentage: "<< dis_percent<<"%"<<endl;

//Applying the discount percentage and subtracting the difference
dis_amount = (dis_percent*og_amount)/100;
dis_price = og_amount - dis_amount;
cout<<"Discounted Price: $"<<dis_price<<endl;

//Applying the discounted price and the tax for the final price
dis_price = dis_price + tax;
cout<<"Final Price after tax : $"<<dis_price<<endl;
return 0;
}
