// Nikunj Pradhan
// 18261640
// npgzx
// 303
// 11.14.2023
// File: main.cpp
// Purpose: This is the main file for lab12

#include <iostream>
#include "header.h"

int main()
{
  int runner = 1;
  int run = 1;
  int size = 5;
  Student students[size];
  double marks[size];

  for(int x=0;x<size;x++)
  {
  std::cout<<"Enter roll number for student "<<runner<<": ";
  std::cin>>students[x].rollNumber;
  std::cout<<"Enter name for student "<<runner<<": ";
  std::cin>>students[x].name;
  std::cout<<"Enter age number for student "<<runner<<": ";
  std::cin>>students[x].age;
  std::cout<<"Enter marks number for student "<<runner<<": ";
  std::cin>>students[x].marks;
  runner++;
  }

  for(int x=0;x<size;x++)
  {
  marks[x] = students[x].marks;
  }

  assignGrades(students,size);
  double max = findMaxMarks(marks,size);
  double age = calculateAverageAge(students,size);

  std::cout<<"\nStudent Information:"<<std::endl;
  for(int x = 0;x<size;x++)
  {
   std::cout<<"Student "<<run<<" - Roll Number: "<<students[x].rollNumber<<", Name: "<<students[x].name<<", Age: "<<students[x].age<<", Marks: "<<students[x].marks<<", Grade: "<<students[x].grade<<std::endl;
   run++;
  }
  std::cout<<"Marks Array: "<<students[0].marks<<" "<<students[1].marks<<" "<<students[2].marks<<" "<<students[3].marks<<" "<<students[4].marks<<std::endl;
  std::cout<<"\nMaximum Marks: "<<max<<std::endl;
  std::cout<<"\nAverage Age: "<<age<<std::endl;
  std::cout<<"\nStudent Information whose age is greater than the average Age: "<<std::endl;
  for(int x = 0;x<size;x++)
  {
  if(students[x].age > age)
   std::cout<<"Student "<<x+1<<" - Roll Number: "<<students[x].rollNumber<<", Name: "<<students[x].name<<", Age: "<<students[x].age<<", Marks: "<<students[x].marks<<", Grade: "<<students[x].grade<<std::endl;
  }
  return 0;
}
