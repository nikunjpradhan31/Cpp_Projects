//Nikunj Pradhan
// 303
// npgzx
// 11.14.2023
// 18261640
// File: header.h
// Purpose: Header file for lab12
#ifndef HEADER_H
#define HEADER_H

struct Student
{
  int rollNumber, age;
  double marks;
  std::string name, grade;
};
//Description: This function finds the highest grade among the students
//Pre: An array with all the marks, and the size of the array
//Post: returns the maximum of the marks
double findMaxMarks(const double marks[], int size);
//Description: Finds the average of the students ages
//Pre: An array with all the student data, and the size of the array
//Post: return the average of all the students ages
double calculateAverageAge(const Student students[], int size);
//Description: This function adds a letter grade to the Grade variable in each students
//Pre: An array with all the student data, and the size of the array
//Post: Changes the grade variable within the array
void assignGrades(Student students[], int size);


#endif
