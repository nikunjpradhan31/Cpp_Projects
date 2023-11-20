// Nikunj Pradhan
// npgzx
// 18261640
// 10.21.2023
// 303
// File: armstrong function to lab10

#include<iostream>
#include "Header.h"
#include<cmath>

bool isArmstrong(int num)
{
  int trial = num;
  int sum = 0;
  do{
   sum += pow(trial%10,3);
   trial/=10;
  }while(trial != 0);
  if(num == sum)
    return true;
  else
    return false;
}
