// Homework Development.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <fstream>
using namespace std;

const int SIZE = 5;

class studentType
{
private:
    string studentFName;
    string studentLName;
    int testScore;
    char grade;

public:
    // Default constructor
    studentType()
    {
        studentFName = "";
        studentLName = "";
        testScore = 0;
        grade = ' ';
    }

    // Parameterized constructor
    studentType(string fName, string lName, int score)
    {
        studentFName = fName;
        studentLName = lName;
        testScore = score;
        grade = ' ';
    }

    // Setters
    void setFName(string fName) { studentFName = fName; }
    void setLName(string lName) { studentLName = lName; }
    void setTestScore(int score) { testScore = score; }
    void setGrade(char g) { grade = g; }

    // Getters
    string getFName()   const { return studentFName; }
    string getLName()   const { return studentLName; }
    int getTestScore()  const { return testScore; }
    char getGrade()     const { return grade; }

    // Member function to assign the grade letter based on testScore
    void assignGrade()
    {
        if (testScore >= 90)
            grade = 'A';
        else if (testScore >= 80)
            grade = 'B';
        else if (testScore >= 70)
            grade = 'C';
        else if (testScore >= 60)
            grade = 'D';
        else
            grade = 'F';
    }

    // Member function to print one formatted student row
    void print() const
    {
        cout << studentLName << ", " << studentFName
            << ": " << testScore << "% " << grade << endl;
    }
};

// -------------------------------------------------------
// Read student data from file into the array
// -------------------------------------------------------
void readFile(studentType students[])
{
    ifstream inFile("students.txt");  //!!!PASTE DIRECTORY HERE

    if (!inFile)
    {
        cout << "Error: Could not open students.txt" << endl;
        return;
    }

    string fName, lName;
    int score;

    for (int i = 0; i < SIZE; i++)
    {
        inFile >> fName >> lName >> score;
        students[i].setFName(fName);
        students[i].setLName(lName);
        students[i].setTestScore(score);
    }

    inFile.close();
}

// -------------------------------------------------------
// Call assignGrade() on every student in the array
// -------------------------------------------------------
void assignAllGrades(studentType students[])
{
    for (int i = 0; i < SIZE; i++)
        students[i].assignGrade();
}

// -------------------------------------------------------
// Print the full formatted results list
// -------------------------------------------------------
void printResults(studentType students[])
{
    cout << "=== Student Results ===" << endl;
    for (int i = 0; i < SIZE; i++)
        students[i].print();
}

// -------------------------------------------------------
// Find and print the student with the highest score
// -------------------------------------------------------
void printHighestScore(studentType students[])
{
    int highIndex = 0;
    for (int i = 1; i < SIZE; i++)
    {
        if (students[i].getTestScore() > students[highIndex].getTestScore())
            highIndex = i;
    }

    cout << "\n=== Highest Score ===" << endl;
    cout << students[highIndex].getFName() << " " << students[highIndex].getLName()
        << " achieved the highest score with a "
        << students[highIndex].getTestScore() << "% ("
        << students[highIndex].getGrade() << ")." << endl;
}

// -------------------------------------------------------
// main() contains only function calls
// -------------------------------------------------------
int main()
{
    studentType students[SIZE];

    readFile(students);
    assignAllGrades(students);
    printResults(students);
    printHighestScore(students);

    return 0;
}