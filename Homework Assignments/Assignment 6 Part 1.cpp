#include <iostream>
#include <sstream>
#include "newString.h"
using namespace std;

// -------------------------------------------------------
// Free function: length
// -------------------------------------------------------
int length(const newString& s)
{
    ostringstream oss;
    oss << s;
    return (int)oss.str().length();
}

// -------------------------------------------------------
// Free function: operator+  (concatenation)
// Streams both objects into one ostringstream and
// constructs a new newString from the combined c_str.
// -------------------------------------------------------
newString operator+(const newString& a, const newString& b)
{
    ostringstream oss;
    oss << a << b;
    return newString(oss.str().c_str());
}

// -------------------------------------------------------
// Free function: operator+=  (append in place)
// Delegates to operator+ and assigns the result back.
// -------------------------------------------------------
newString& operator+=(newString& a, const newString& b)
{
    a = a + b;
    return a;
}

// -------------------------------------------------------
// Test Program
// -------------------------------------------------------
int main()
{
    cout << "=== newString Test Program ===" << endl;

    // --- Creating newString objects ---
    newString s1("Hello");
    newString s2(" World");
    newString s3;

    cout << "\n-- Creation --" << endl;
    cout << "s1: " << s1 << endl;
    cout << "s2: " << s2 << endl;

    // --- input operator ---
    cout << "\n-- Input (>>) --" << endl;
    cout << "Enter a word for s3: ";
    cin >> s3;
    cout << "s3: " << s3 << endl;

    // --- length() ---
    cout << "\n-- length() --" << endl;
    cout << "length(s1) = " << length(s1) << endl;
    cout << "length(s2) = " << length(s2) << endl;
    cout << "length(s3) = " << length(s3) << endl;

    // --- operator+ ---
    cout << "\n-- Concatenation (+) --" << endl;
    newString s4 = s1 + s2;
    cout << "s1 + s2 = \"" << s4 << "\"" << endl;

    newString s5 = s4 + newString(" ") + s3;
    cout << "s4 + \" \" + s3 = \"" << s5 << "\"" << endl;

    // --- operator+= ---
    cout << "\n-- Append in Place (+=) --" << endl;
    newString s6("Goodbye");
    cout << "s6 before +=: \"" << s6 << "\"" << endl;
    s6 += newString(" Everyone");
    cout << "s6 after  +=: \"" << s6 << "\"" << endl;

    // --- Relational operators (original, unchanged) ---
    cout << "\n-- Relational Operators --" << endl;
    newString a("Apple");
    newString b("Banana");
    newString c("Apple");

    cout << "a = \"" << a << "\",  b = \"" << b << "\",  c = \"" << c << "\"" << endl;
    cout << "a == c : " << (a == c ? "true" : "false") << endl;
    cout << "a != b : " << (a != b ? "true" : "false") << endl;
    cout << "a <  b : " << (a < b ? "true" : "false") << endl;
    cout << "a <= c : " << (a <= c ? "true" : "false") << endl;
    cout << "b >  a : " << (b > a ? "true" : "false") << endl;
    cout << "b >= a : " << (b >= a ? "true" : "false") << endl;

    // --- output operator (original, unchanged) ---
    cout << "\n-- Output (<<) --" << endl;
    cout << "s5 via <<: " << s5 << endl;

    return 0;
}