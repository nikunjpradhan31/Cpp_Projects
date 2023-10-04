// Nikunj Pradhan
// 18261640
// 303
// 10/3/2023
// lab4.cpp
// Purpose: Calculate Sales and Total
#include <iostream>
using namespace std;

  double calculateSalesTax(double price, double tax_percent );
  float calculateTotalWithTax(double price, double sales_tax);
  void printReceipt(string itemName, double itemPrice, double salesTax, float totalPrice);

int main()
{
  string item;
  char cont = 'Y';
  double itemPrice, tax;
  int state, choice;

 do{ //do while loop that allows user to repeat the program

  cout<<"\nItem Name: ";
  cin>>item;
  cout<<"\nPrice of item: ";
  cin>>itemPrice;
  cout<<"\nEnter the state: \n1 for MO \n2 for CA \n3 for NY \n4 for TX"<<endl;
  cin>>state;
 //gathers the user data
  switch(state){//swtich cases that gather information based on the state and its tax
  case 1:
   tax = 0.05;
   break;
  case 2:
   tax = 0.09;
   break;
  case 3:
   tax  =0.08875;
   break;
  case 4:
   tax = 0.0625;
   break;
  default:
   tax = 0;
   break;
  }
  double sales_tax = calculateSalesTax(itemPrice, tax);
  float total_price = calculateTotalWithTax(itemPrice, sales_tax);
  cout<<"\nCalculated Tax amount: $"<<sales_tax<<endl;
  cout<<"\nCalculated Total price: $"<<total_price<<endl;
  cout<<"\nDo you wish to print reciept? Enter your choice 0/1 (0->No / 1->Yes): ";
  cin>>choice;

  (choice == 1) ? printReceipt(item, itemPrice, sales_tax, total_price): void(); //asks user if they wan the receipt
  cout<<"\nWould you like to continue (Y/N): "; 
  cin>>cont;
 }while(cont == 'Y');
return 0;
}

double calculateSalesTax(double price, double tax_percent ){
  double tax_amount = price * tax_percent; 
  return tax_amount;
}

float calculateTotalWithTax(double price, double sales_tax){

  float total_price = price + sales_tax; 
  return total_price;
}

void printReceipt(string itemName, double  itemPrice, double  salesTax, float  totalPrice)
{
cout<<"\n********************\nItem Name: "<< itemName<<"\nPrice: $"<<itemPrice<<"\nSales Tax: $"<<salesTax<<"\nTotal Price: $"<<totalPrice<<"\n********************\n"<<endl;



}
