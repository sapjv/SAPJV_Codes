/*

           ###  Substring in C++  ###
           
In C++, std::substr() is a predefined function used for string handling. 
string.h is the header file required for string functions.

This function takes two values pos and len as an argument and returns a newly 
constructed string object with its value initialized to a copy of a sub-string 
of this object. Copying of string start from pos and done till pos+len means [pos, pos+len).

Important points:

1. The index of the first character is 0 (not 1).
2. If pos is equal to the string length, the function returns an empty string.
3. If pos is greater than the string length, it throws out_of_range. If this 
   happen, there are no changes in the string.
4. If for the requested sub-string len is greater than size of string, then 
   returned sub-string is [pos, size()).


Syntax:
string substr (size_t pos, size_t len) const;

Parameters:
pos: Position of the first character to be copied.
len: Length of the sub-string.
size_t: It is an unsigned integral type.

Return value: It returns a string object.

*/



#include<bits/stdc++.h>
using namespace std;
   
int main()
{
   ios_base::sync_with_stdio(false);
   cin.tie(NULL);
   
   string s1 = "Geeks";                // Take any string 
   string r = s1.substr(1, 3);         // Copy three characters of s1 (starting from position 1) 
   cout << "String is: " << r;         // prints the result ( String is: eek )

   // ......................

   /*
   Applications :

   Question :  How to get sub-string after a character?
   Answer :  If a string and a character is given and you have to print the 
             sub-string followed by the given character. like : Extract everything 
             after the “:” in the string “dog:cat”.
   */

   string s = "dog:cat";                  // Take any string
   int pos = s.find(":");                 // Find position of ':' using find()
   string sub = s.substr(pos + 1);        // Copy substring after pos
   cout << "\nString is: " << sub;          // prints the result ( String is: cat )
}
