// converting string to integer and integer to string

#include<bits/stdc++.h>
using namespace std;
int main()
{
    
    // converting string to integer using stoi()
    string str1 = "45"; 
    string str2 = "3.14159"; 
    string str3 = "31337 geek"; 
  
    int myint1 = stoi(str1);             // output : 45
    
    // note the output of float and double ( the output of stoi() will be only and only integer value )
    int myint2 = stoi(str2);            // output : 3 ( important output)
    int myint3 = stoi(str3);            // output : 31337 ( important output)
  
    cout << "stoi(\"" << str1 << "\") is "<< myint1 << '\n'; 
    cout << "stoi(\"" << str2 << "\") is "<< myint2 << '\n'; 
    cout << "stoi(\"" << str3 << "\") is "<< myint3 << "\n\n\n"; 
  
  
    // --------------------------------------------------
    
    
    // converting integer to string using to_string()
    int i_val = 20; 
    float f_val = 30.50; 
  
    string str_i = to_string(i_val); 
    string str_f = to_string(f_val); 
  
    // Displaying the converted strings 
    cout << "The integer in string is : "<<str_i << endl; 
    cout << "The float in string is : "<< str_f << endl; 
}
