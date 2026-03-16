// HW Assignment Developmet.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
using namespace std;

int smallestIndex(int arr[], int size) //Smallest Index Function
{
    int minIndex = 0;
    for (int i = 1; i < size; i++)  //Loop set for finding the smallest element
    {
        if (arr[i] < arr[minIndex]) //Check for smallest element
            minIndex = i;
    }
    return minIndex;
}

bool isVowel(char c) //Vowel Function
{
    c = tolower(c);
    return (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u');
}

int main()
{
    // Problem 1 Part 1: Single character check
    char chp1;
    cout << "Enter a character: "; //Prompt
    cin >> chp1;

    if (isVowel(chp1))
        cout << chp1 << " is a vowel." << endl; //True Result
    else
        cout << chp1 << " is not a vowel." << endl; //False Result

    // Problem 1 Part 2: Sequence/word vowel count
    string inputp1;
    cout << "\nEnter a sequence of characters or a word: "; //Prompt
    cin >> inputp1;

    int vowelCount = 0;
    for (int i = 0; i < inputp1.length(); i++) //Loop set as input length
    {
        if (isVowel(inputp1[i])) //Check for vowel
            vowelCount++; //tick up vowelcount
    }

    cout << "Number of vowels in \"" << inputp1 << "\": " << vowelCount << endl; //Result Output

    // Problem 2: Remove vowels from a string using a substr function
    string inputp2;
    cout << "\nEnter a string to have its vowels removed: "; //prompt
    cin >> inputp2;

    string result = "";
    for (int i = 0; i < inputp2.length(); i++) //Loop set as input length
    {
        if (!isVowel(inputp2[i])) //Check for vowel
            result += inputp2.substr(i, 1); //Remove vowel (if any)
    }

    cout << "String with vowels removed: " << result << endl; //Result Output

    // Problem 3 Part 1: Smallest element finder with a sample array
    int sample[] = { 34, 12, 7, 45, 3, 28, 19 };
    int sampleSize = 7;

    cout << "\n--- Sample Array ---" << endl;
    cout << "Array: ";
    for (int i = 0; i < sampleSize; i++) //Loop for size
        cout << sample[i] << " ";
    cout << endl;
    cout << "Smallest element: " << sample[smallestIndex(sample, sampleSize)] << endl; //Result: Smallest element
    cout << "Found at index:   " << smallestIndex(sample, sampleSize) << endl;  //Result: Smallest element location

    // Problem 3 Part 2: Smallest element finder with a user-defined array
    int userSize;
    cout << "\n--- User-Defined Array ---" << endl;
    cout << "Enter the number of elements: ";
    cin >> userSize; //Set array size

    int* userArr = new int[userSize];
    cout << "Enter " << userSize << " integers: "; 
    for (int i = 0; i < userSize; i++) //Prompt for elements based on size input
        cin >> userArr[i]; //Index value input from first to last

    cout << "Smallest element: " << userArr[smallestIndex(userArr, userSize)] << endl; //Result: Smallest element
    cout << "Found at index:   " << smallestIndex(userArr, userSize) << endl;   //Result: Smallest element location

    delete[] userArr;

    return 0;
}

