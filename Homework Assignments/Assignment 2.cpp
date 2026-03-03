// Homework Development.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <fstream>
using namespace std;

//Problem 1 Prerequisites
struct Person
{
    string name;
    int age;
    string gender;
    int feet;
    int inches;
    double weight;
}user; //Structure of variables

double calculateBMI(Person p)
{
    int totalInches = (p.feet * 12) + p.inches;
    return (p.weight / (totalInches * totalInches)) * 703;
} //BMI Calculation function

string getWeightCategory(double bmi)
{
    if (bmi < 16)
        return "Severe Thinness";
    else if (bmi < 17)
        return "Moderate Thinness";
    else if (bmi < 18.5)
        return "Mild Thinness";
    else if (bmi < 25)
        return "Normal";
    else if (bmi < 30)
        return "Overweight";
    else if (bmi < 35)
        return "Obese Class I";
    else if (bmi < 40)
        return "Obese Class II";
    else
        return "Obese Class III";
} //Reference chart of weight categories



//Problem 2 Prerequistites

const int SIZE = 5; //Set Array Size

struct studentType  //Student Structure
{
    string studentFName;
    string studentLName;
    int testScore;
    char grade;
};

void readFile(studentType students[]) //File Read Function
{
    ifstream inFile("D:/Documents/School Docs/students.txt"); //!!!DIRECTORY FOR FILE, SET TO FILE LOCATION FOR PROPER EXECUTION!!!

    if (!inFile)
    {
        cout << "Error: Could not open students.txt" << endl;
        return;
    }

    for (int i = 0; i < SIZE; i++) //Read and write file contents
        inFile >> students[i].studentFName >> students[i].studentLName >> students[i].testScore;

    inFile.close();
}

char assignLetterGrade(int score) //Letter grade funtion
{
    if (score >= 90)
        return 'A';
    else if (score >= 80)
        return 'B';
    else if (score >= 70)
        return 'C';
    else if (score >= 60)
        return 'D';
    else
        return 'F';
}

void assignGrades(studentType students[])  //Assign letter grade algorithm
{
    for (int i = 0; i < SIZE; i++)
        students[i].grade = assignLetterGrade(students[i].testScore);
}

void printResults(studentType students[])  //Grade assigning algorithm
{
    cout << "\n=== Student Results ===" << endl;
    for (int i = 0; i < SIZE; i++)
    {
        cout << students[i].studentLName << ", " << students[i].studentFName
            << ": " << students[i].testScore << "% "
            << students[i].grade << endl;
    }
}

void printHighestScore(studentType students[]) //Highest score alogorithm
{
    int highIndex = 0;
    for (int i = 1; i < SIZE; i++)
    {
        if (students[i].testScore > students[highIndex].testScore)
            highIndex = i;
    }

    cout << "\n=== Highest Score ===" << endl;
    cout << students[highIndex].studentFName << " " << students[highIndex].studentLName
        << " achieved the highest score with a " << students[highIndex].testScore
        << "% (" << students[highIndex].grade << ")." << endl;
}

int main()
{
    //Problem 1: BMI Calculator and Summary

    Person user; //Call Structure and begin inputs

    cout << "=== BMI Calculator ===" << endl;

    cout << "\nEnter your name: ";
    cin >> user.name;

    cout << "Enter your age: ";
    cin >> user.age;

    cout << "Enter your biological sex (Male/Female): ";
    cin >> user.gender;

    cout << "Enter your height (feet): ";
    cin >> user.feet;

    cout << "Enter your height (inches): ";
    cin >> user.inches;

    cout << "Enter your weight (lbs): ";
    cin >> user.weight;

    double bmi = calculateBMI(user); //hook variable with BMI function for calculation
    string category = getWeightCategory(bmi);

    int totalInches = (user.feet * 12) + user.inches;
    int displayFeet = totalInches / 12;
    int displayInches = totalInches % 12;

    cout << "\n=== Results ===" << endl; //Output execution to summarize the user's BMI
    cout << user.name << " is a " << user.age << "-year-old " << user.gender << " standing "
         << displayFeet << " ft " << displayInches << " in tall and weighing "
         << user.weight << " lbs." << endl;
    cout << "Their calculated BMI score is " << bmi << " kg/m2, which places them in the \""
         << category << "\" weight category." << endl;

    //Problem 2: Student Score Indexer

    studentType students[SIZE];

    readFile(students);
    assignGrades(students);
    printResults(students);
    printHighestScore(students);

    return 0;
}

void Default_Values(Person p)
{
    Person user;
    user.name = "null";
    user.age = 0;
    user.feet = 0;
    user.inches = 0;
    user.weight = 0;
} //Default Values