/*

         ### string find in C++  ###
         
String find is used to find the first occurrence of sub-string in the 
specified string being called upon. It returns the index of the first 
occurrence of the substring in the string from given starting position. 
The default value of starting position is 0.

Function Template:
size_t find (const string& str, size_t pos = 0);
size_t find (const char* s, size_t pos = 0);

Function parameters:
str : The sub-string to be searched.
s : The sub-string to be searched, given as C style string.
pos : The initial position from where the string search is to begin.

Function Return: The function returns the index of the first occurrence 
of sub-string, if the sub-string is not found it returns string::npos(string::pos 
is static member with value as the highest possible for the size_t data structure).

*/

#include<bits/stdc++.h>
using namespace std;
   
int main()
{
   ios_base::sync_with_stdio(false);
   cin.tie(NULL);
   
   string str = "geeksforgeeks a computer science"; 
   string str1 = "geeks"; 
  
   size_t found = str.find(str1);            // Find first occurrence of "geeks"
   if (found != string::npos) 
     cout << "First occurrence is " << found << endl; 
 
   char arr[] = "geeks";               // Find next occurrence of "geeks". Note here we pass "geeks" as C style string.
   found = str.find(arr, found+1); 
   if (found != string::npos) 
     cout << "Next occurrence is " << found << endl; 

   // ..........................

   /*
      We can also use it to find occurrence of a character:
      In below syntax, note that c is a character.

      size_t find (const char c, size_t pos = 0);
   */
   
   string str2 = "geeksforgeeks a computer science"; 
   char c2 = 'g'; 

   size_t found2 = str2.find(c2);              // Find first occurrence of 'g' 
   if (found2 != string::npos) 
     cout << "First occurrence is " << found2 << endl; 

   found2 = str2.find(c2, found2+1);            // Find next occurrence of 'g'  
   if (found2 != string::npos) 
     cout << "Next occurrence is " << found2 << endl; 

   // ..........................

   /*
      We can also search for a partial string.
      In below syntax, note that n is number of characters to match.

      size_t find (const char *str, size_t pos, size_t n);
   */
   
   string str3 = "geeksforgeeks a computer science"; 

   size_t found3 = str3.find("geeks.practice", 0, 5);            // Only search first 5 characters of "geeks.practice" 
   if (found3 != string::npos) 
     cout << "found at : " << found3 << endl; 
}

/*

Output :

First occurrence is 0
Next occurrence is 8
First occurrence is 0
Next occurrence is 8
found at : 0

*/
