/*

      string transform() to uppercase or lowercase in C++

Conversion of whole String to uppercase or lowercase using STL in C++
Given a string, convert the whole string to uppercase or lowercase using STL in C++.

Examples:

For uppercase conversion
Input : s = "String"
Output : s = "STRING"

For lowercase conversion
Input : s = "String"
Output : s = "string"

Functions used :

transform() : Performs a transformation on given array/string.

toupper(int c) : Returns upper case version of character c. If c is already 
                 in uppercase, return c itself.
                 
tolower(int c) : Returns lower case version of character c. If c is already 
                 in lowercase, return c itself.


*/

#include<bits/stdc++.h>
using namespace std;
   
int main()
{
   ios_base::sync_with_stdio(false);
   cin.tie(NULL);
   
   string su = "Jatin Goyal";         // su is the string which is converted to uppercase
   transform(su.begin(), su.end(), su.begin(), ::toupper);         // using transform() function and ::toupper in STL 
   cout << su << endl;          // Output : JATIN GOYAL

   string sl = "Jatin Goyal";        // sl is the string which is converted to lowercase 
   transform(sl.begin(), sl.end(), sl.begin(), ::tolower);         // using transform() function and ::tolower in STL 
   cout << sl << endl;          // Output : jatin goyal
}
