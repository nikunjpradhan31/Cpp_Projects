// Nikunj Pradhan
// npgzx
// 18261640
// 303
// 11.14.2023
// File: functions.cpp
// Purpose: functions file for Lab12

#include <iostream>
#include "header.h"
double findMaxMarks(const double marks[], int size)
{
  double max = 0;
  for(int x =0; x<size;x++)
  {
   if(marks[x] > max)
     max = marks[x];
  }
  return max;
}
double calculateAverageAge(const Student students[], int size)
{
  double age = 0;
  for(int x = 0; x<size; x++)
  {
   age += static_cast<double>(students[x].age);
  }
  return age/size;
}
void assignGrades(Student students[], int size)
{
  for(int x = 0;x<size;x++)
  {
   double temp = students[x].marks;
   if(temp >=90)
    students[x].grade = "A";
   else if(temp >=80)
    students[x].grade = "B";
   else if(temp >=70)
    students[x].grade = "C";
   else if(temp >=60)
    students[x].grade = "D";
   else
    students[x].grade = "F";
  }
}
