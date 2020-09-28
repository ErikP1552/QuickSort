//
//  main.cpp
//  HW6QuickSort
//
//  Created by Erik on 10/2/19.
//  Copyright © 2019 Erik. All rights reserved.
//

//Included Libraries
#include <iostream>
#include <vector>
#include <fstream>
#include <string>
#include <iomanip>

using namespace std;

class QuickSort // All functions and data - going through class
{
    /* Student records should include Student ID, Name, GPA, Student Address, and
    a pointer which points to (10+) test scores for each student record located  somewhere in the program or from a second file.*/
    
public:
    struct student
    {
        int studentID;
        string studentName; //
        string studentAddress;
        float GPA;
        int *testScore; // using array pointer to store records
    };
    
    // Format Functions
    void introduction(); // For readability
    void conclusion(); // For readability
    // Utility Functions
    student push(student);
    student pop();
    bool readFile(vector <student> &studentList, string infile);
    void print(vector<student> const &input);
    int partition(vector<student> &input,int low, int high);
    void quickSort1(vector<student> &input, int low, int high);
    void swap(int* a, int* b);
    void print2(vector<student> x);
};

int main() {
    QuickSort object1; // Creating object
    object1.introduction(); // For readability
    vector<QuickSort::student> studentList; // Vector to hold the student records
    vector<QuickSort::student> studentList2; // Vector to hold the student records
    vector<QuickSort::student> studentList3; // Vector to hold the student records
    QuickSort::student data;
    string infile("/users/erik/desktop/HW6QuickSort/grades.txt");
    string infile2("/users/erik/desktop/HW6QuickSort/grades.txt");
    string infile3("/users/erik/desktop/HW6QuickSort/grades.txt");
    //Task 1, Task 2 - save records from file to vector of structs with student grades
    if(!object1.readFile(studentList, infile)) // Adding Student records from text file
    {
    cout << "ERROR: Could not read the input file (grades)" << endl;
    return 1;
    }
    // Adding Sample grades to records for task 4 - 5
    int a1[10] = {86,68,50,99,67,97,54,65,35,71};studentList.at(0).testScore = a1;
    int a2[10] = {98,68,50,99,67,94,50,96,90,77};studentList.at(1).testScore = a2;
    int a3[10] = {85,68,56,15,67,97,54,65,35,70};studentList.at(2).testScore = a3;
    int a4[10] = {86,68,50,99,58,86,59,98,35,77};studentList.at(3).testScore = a4;
    int a5[10] = {86,79,50,99,67,97,90,65,97,77};studentList.at(4).testScore = a5;
    int a6[10] = {53,68,53,76,67,97,57,98,35,74};studentList.at(5).testScore = a6;
    int a7[10] = {86,68,50,39,88,97,54,65,35,77};studentList.at(6).testScore = a7;
    int a8[10] = {34,67,50,99,67,90,56,65,35,72};studentList.at(7).testScore = a8;
    int a9[10] = {86,68,26,99,67,97,78,99,99,77};studentList.at(8).testScore = a9;
    int a10[10] = {99,66,50,99,54,96,54,65,35,76};studentList.at(9).testScore = a10;
    int a11[10] = {86,68,50,99,67,97,54,65,35,71};studentList.at(10).testScore = a11;
    int a12[10] = {98,38,50,39,67,94,50,96,90,77};studentList.at(11).testScore = a12;
    int a13[10] = {22,68,56,53,67,97,54,65,35,70};studentList.at(12).testScore = a13;
    int a14[10] = {86,58,50,99,58,86,59,98,35,77};studentList.at(13).testScore = a14;
    int a15[10] = {86,79,50,99,67,97,90,65,97,77};studentList.at(14).testScore = a15;
    //Task 3 - display all records/including scores - could use POP
       cout << "Task 1 - 3 - Displaying all records in vector including scores "<<endl<<endl;
       object1.print(studentList);
       cout <<" -------------------------------------------------------------------------------------"<<endl;
    //Task 4/5 - display all records/including scores - could use POP
        cout << "Task  4 - 5 - Displaying all records in vector including scores after using recurrsion sort"<<endl<<endl;
    int size0 = 15;
    object1.quickSort1(studentList, 0, size0 - 1);
    object1.print(studentList);
        cout <<" -------------------------------------------------------------------------------------"<<endl;
    //Task 6 - display all records/including scores - could use POP
        cout << "Task 6 - Sort 2 other sets of records and display lists "<<endl<<endl;
    cout << "Second List uploaded from seperate .txt file and sorted using Quick Sort: " <<endl;
    if(!object1.readFile(studentList2, infile2)) // Adding Student records from text file
       {
       cout << "ERROR: Could not read the input file 2 (Grades2) " << endl;
       return 1;
       }
     //Grades for 2nd set of Records used in task 6
      int b1[10] = {86,68,50,99,67,97,54,65,35,71}; studentList2.at(0).testScore = b1;
      int b2[10] = {86,68,50,99,67,97,54,65,35,71}; studentList2.at(1).testScore = b2;
      int b3[10] = {86,68,50,99,67,97,54,65,35,71}; studentList2.at(2).testScore = b3;
      int b4[10] = {34,67,50,99,67,90,56,65,35,72}; studentList2.at(3).testScore = b4;
      int b5[10] = {22,68,56,53,67,97,54,65,35,70}; studentList2.at(4).testScore = b5;
      int b6[10] = {86,68,50,99,67,97,54,65,35,71}; studentList2.at(5).testScore = b6;
      int b7[10] = {98,68,50,99,67,94,50,96,90,77}; studentList2.at(6).testScore = b7;
      int b8[10] = {98,68,50,99,67,94,50,96,90,77}; studentList2.at(7).testScore = b8;
      int b9[10] = {86,58,50,99,58,86,59,98,35,77}; studentList2.at(8).testScore = b9;
      int b10[10] = {86,58,50,99,58,86,59,98,35,77}; studentList2.at(9).testScore = b10;
    int size2 = 10;
    object1.quickSort1(studentList2, 0, size2 - 1);
    object1.print2(studentList2);
     cout << "Third List uploaded from seperate .txt file and sorted using Quick Sort: " <<endl;
    if(!object1.readFile(studentList3, infile3)) // Adding Student records from text file
       {
       cout << "ERROR: Could not read the input file 3 (Grades3)" << endl;
       return 1;
       }
    //Grades for 3rd set of records using in task 6
    int c1[10] = {98,68,50,99,67,94,50,96,90,77}; studentList3.at(0).testScore = c1;
    int c2[10] = {86,58,50,99,58,86,59,98,35,77}; studentList3.at(1).testScore = c2;
    int c3[10] = {86,68,50,99,67,97,54,65,35,71}; studentList3.at(2).testScore = c3;
    int c4[10] = {22,68,56,53,67,97,54,65,35,70}; studentList3.at(3).testScore = c4;
    int c5[10] = {86,68,50,99,67,97,54,65,35,71}; studentList3.at(4).testScore = c5;
    int c6[10] = {86,68,50,99,67,97,54,65,35,71}; studentList3.at(5).testScore = c6;
    int c7[10] = {86,58,50,99,58,86,59,98,35,77}; studentList3.at(6).testScore = c7;
    int c8[10] = {86,68,50,99,67,97,54,65,35,71}; studentList3.at(7).testScore = c8;
    int c9[10] = {86,68,50,99,67,97,54,65,35,71};studentList3.at(8).testScore = c9;
    int c10[10] = {86,68,50,99,67,97,54,65,35,71}; studentList3.at(9).testScore = c10;
    int size3 = 10;
    object1.quickSort1(studentList3, 0, size3 - 1);
    object1.print2(studentList3);
        cout <<" -------------------------------------------------------------------------------------"<<endl;
    
    return 0;
}

void QuickSort::introduction(){
      cout <<"Asssignment 6 Quick Sort  " << endl<<endl;
      cout <<"This program will:" <<endl<<endl;
      cout <<"1. Upload from a external file of at least 15 student records unsorted" <<endl;
      cout <<"2. Read student records into a vector " <<endl;
      cout <<"3. Display the 15+ student records (entire record, not just ID) and associated test scores." <<endl;
      cout <<"4. Use QuickSort and recursion to Sort the student records according to student ID or GPA. "<<endl;
      cout <<"5. Display the sorted list of student records (entire record, not just ID) and associated test scores. "<<endl;
      cout <<"6. Repeat the above on two sets of student records. Each set with a minimum of 10 records."<<endl<<endl;
      cout <<" -------------------------------------------------------------------------------------"<<endl;
}

void QuickSort::conclusion(){
    
     cout << endl << "Created by Erik Pantoja, For Data Structures Fall 2019 " <<endl<<endl;
    
}

bool QuickSort::readFile(vector <QuickSort::student> &studentList, string infilex)
{
    
ifstream infile(infilex);
    if(infile.fail()){
        return false;
    }
QuickSort::student k;
while(infile >> k.studentID){
infile >> k.studentName >> k.studentAddress >> k.GPA;
studentList.push_back(k);
}
infile.close();
    
return true;
}

void QuickSort::print(vector<student> const &input)
{
    for (int i = 0; i < input.size(); i++) {
        cout << " Student ID is: "<< input.at(i).studentID << "    Student Name is: " << input.at(i).studentName << "    Student Address is: " << input.at(i).studentAddress << "    Student GPA is: " << input.at(i).GPA <<endl;
        cout << "Student " << input.at(i).studentID << " Test Scores are: ";
        for ( int n = 0; n < 10; n++ ) {
        
            cout << (*input.at(i).testScore + n) << " ";
        }
        cout <<endl;
    } cout <<endl;
}

void QuickSort::print2(vector<student> x)
{
    for (int i = 0; i < 10; i++) {
        cout << " Student ID is: "<< x.at(i).studentID << "    Student Name is: " << x.at(i).studentName << "    Student Address is: " << x.at(i).studentAddress << "    Student GPA is: " << x.at(i).GPA <<endl;
        cout << "Student " << x.at(i).studentID << " Test Scores are: ";
        for ( int n = 0; n < 10; n++ ) {
        
            cout << (*x.at(i).testScore + n) << " ";
        }
        cout <<endl;
    } cout <<endl;
}

int QuickSort::partition(vector<student> &input,int low, int high)
{
    int pivot = input.at(high).studentID;
    int i = (low - 1);
  
    for (int j = low; j <= high - 1; j++)
    {
        if (input.at(j).studentID <= pivot)
        {
            i++;
            swap(&input.at(i).studentID, &input.at(j).studentID);
        }
    }
    swap(&input.at(i + 1).studentID, &input.at(high).studentID);
    return (i + 1);
}

void QuickSort::quickSort1(vector<student> &input, int low, int high)
{
    if (low < high)
    {
        int pi = partition(input, low, high);
        quickSort1(input, low, pi - 1);
        quickSort1(input, pi + 1, high);
    }
}

void QuickSort::swap(int* a, int* b)
{
    int t = *a;
    *a = *b;
    *b = t;
}
