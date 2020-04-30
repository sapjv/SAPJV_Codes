#include<iostream>
#include <fstream>			// Input/output stream class to operate on files
using namespace std;
int main()
{
	int n;
	ifstream read("data.txt");			// reading the height.dat file
	while(read>>n)			// till the input ( height ) is present in the file
	{
		cout<<n<<" ";
	}
}
