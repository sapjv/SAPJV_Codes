#include<bits/stdc++.h>
using namespace std;
typedef long long int lli;

#define N 30

int main()
{
    
    /*
    
    A bitset is an array of bool but each Boolean value is not stored separately instead bitset optimizes the 
    space such that each bool takes 1 bit space only, so space taken by bitset bs is less than that of bool bs[N] 
    and vector bs(N). However, a limitation of bitset is, N must be known at compile time, i.e., a constant (this
    limitation is not there with vector and dynamic array)

    As bitset stores the same information in compressed manner the operation on bitset are faster than that of 
    array and vector. We can access each bit of bitset individually with help of array indexing operator [] that 
    is bs[3] shows bit at index 3 of bitset bs just like a simple array. Remember bitset starts its indexing 
    backward that is for 10110 like this : (n-1)th index,(n-2)th index,(n-3)th index,.....,2nd index,1st index,0th index.
    
    We can construct a bitset using integer number as well as binary string via constructors which is shown in 
    below code. The size of bitset is fixed at compile time that is, it can’t be changed at runtime.
    The main function defined for bitset class are operator [], count(), size(), set(), reset() and many more 
    they are explained in below code –
    
    */
    
    // default constructor initializes with all bits 0. Note : here 0th index will be right most bit
    bitset<N> bs;                        // bitset<8> set8; // 00000000 ( declaring set8 with capacity of 8 bits )
    cout<<"bs = "<<bs<<"\n\n";              // output : 000000000000000000000000000000    
    
    bitset<N> bs1(1);               // bs1 is initialized with bits of decimal number 1 
    bitset<N> bs2(2);               // bs2 is initialized with bits of decimal number 2 
    bitset<N> bs3(4);               // bs3 is initialized with bits of decimal number 4 
    bitset<N> bs4(8);               // bs4 is initialized with bits of decimal number 8 
    bitset<N> bs5(16);              // bs5 is initialized with bits of decimal number 16 
    bitset<N> bs6(32);              // bs6 is initialized with bits of decimal number 32 
    bitset<N> bs7(64);              // bs7 is initialized with bits of decimal number 64 
    bitset<N> bs8(128);             // bs8 is initialized with bits of decimal number 128
    
    cout<<"bs1 = "<<bs1<<"\n";              // output : 000000000000000000000000000001 
    cout<<"bs2 = "<<bs2<<"\n";              // output : 000000000000000000000000000010 
    cout<<"bs3 = "<<bs3<<"\n";              // output : 000000000000000000000000000100 
    cout<<"bs4 = "<<bs4<<"\n";              // output : 000000000000000000000000001000 
    cout<<"bs5 = "<<bs5<<"\n";              // output : 000000000000000000000000010000 
    cout<<"bs6 = "<<bs6<<"\n";              // output : 000000000000000000000000100000 
    cout<<"bs7 = "<<bs7<<"\n";              // output : 000000000000000000000001000000 
    cout<<"bs8 = "<<bs8<<"\n\n";            // output : 000000000000000000000010000000 
    
    bitset<N> bs9(20);
    cout<<"bs9 = "<<bs9<<"\n";              // output : 000000000000000000000000010100 
    
    bitset<N> bs10(40);
    cout<<"bs10 = "<<bs10<<"\n";            // output : 000000000000000000000000101000 
    
    bitset<N> bs11(60);
    cout<<"bs11 = "<<bs11<<"\n\n";          // output : 000000000000000000000000111100 
    
    // bitset supports [] operator too for accessing a particular index bit
    // we have bs1 = 000000000000000000000000000001 , bs2 = 000000000000000000000000000010
    cout<<"bs1[0] = "<<bs1[0]<<"\n";                    // output : 1
    cout<<"bs1[1] = "<<bs1[1]<<"\n";                    // output : 0
    cout<<"bs2[0] = "<<bs2[0]<<"\n";                    // output : 0
    cout<<"bs2[1] = "<<bs2[1]<<"\n\n";                    // output : 1
    
    
    // bs12,bs13,bs14 is initialized with bits of specified binary string 
    bitset<N> bs12(string("110101110101010"));
    cout<<"bs12 = "<<bs12<<"\n";              // output : 000000000000000110101110101010 
    bitset<N> bs13(string("1111111"));
    cout<<"bs13 = "<<bs13<<"\n";              // output : 000000000000000000000001111111 
    bitset<N> bs14(string("0101011101"));
    cout<<"bs14 = "<<bs14<<"\n\n";            // output : 000000000000000000000101011101 
    
    
    // count() - This function returns number of set bits in bitset
    cout<<"count_1_in_bs = "<<bs.count()<<"\n";                // output : 0 
    cout<<"count_1_in_bs1 = "<<bs1.count()<<"\n";              // output : 1 
    cout<<"count_1_in_bs2 = "<<bs2.count()<<"\n";              // output : 1 
    cout<<"count_1_in_bs3 = "<<bs3.count()<<"\n";              // output : 1 
    cout<<"count_1_in_bs4 = "<<bs4.count()<<"\n";              // output : 1 
    cout<<"count_1_in_bs5 = "<<bs5.count()<<"\n";              // output : 1 
    cout<<"count_1_in_bs6 = "<<bs6.count()<<"\n";              // output : 1 
    cout<<"count_1_in_bs7 = "<<bs7.count()<<"\n";              // output : 1 
    cout<<"count_1_in_bs8 = "<<bs8.count()<<"\n";              // output : 1 
    cout<<"count_1_in_bs9 = "<<bs9.count()<<"\n";              // output : 2 
    cout<<"count_1_in_bs10 = "<<bs10.count()<<"\n";            // output : 2 
    cout<<"count_1_in_bs11 = "<<bs11.count()<<"\n";            // output : 4 
    cout<<"count_1_in_bs12 = "<<bs12.count()<<"\n";            // output : 9 
    cout<<"count_1_in_bs13 = "<<bs13.count()<<"\n";            // output : 7 
    cout<<"count_1_in_bs14 = "<<bs14.count()<<"\n\n";          // output : 6 
    
    
    // size() - This function returns total number of bits in bitset 
    // Hence, we can easily get total number of unset(0) bits in bitset by 
    // simply subtracting all set bits
    cout<<"count_0_in_bs = "<<bs.size()-bs.count()<<"\n";              // output : 30 
    cout<<"count_0_in_bs1 = "<<bs1.size()-bs1.count()<<"\n";              // output : 29 
    cout<<"count_0_in_bs2 = "<<bs2.size()-bs2.count()<<"\n";              // output : 29 
    cout<<"count_0_in_bs3 = "<<bs3.size()-bs3.count()<<"\n";              // output : 29 
    cout<<"count_0_in_bs4 = "<<bs4.size()-bs4.count()<<"\n";              // output : 29 
    cout<<"count_0_in_bs5 = "<<bs5.size()-bs5.count()<<"\n";              // output : 29 
    cout<<"count_0_in_bs6 = "<<bs6.size()-bs6.count()<<"\n";              // output : 29 
    cout<<"count_0_in_bs7 = "<<bs7.size()-bs7.count()<<"\n";              // output : 29 
    cout<<"count_0_in_bs8 = "<<bs8.size()-bs8.count()<<"\n";              // output : 29 
    cout<<"count_0_in_bs9 = "<<bs9.size()-bs9.count()<<"\n";              // output : 28 
    cout<<"count_0_in_bs10 = "<<bs10.size()-bs10.count()<<"\n";              // output : 28 
    cout<<"count_0_in_bs11 = "<<bs11.size()-bs11.count()<<"\n";              // output : 26 
    cout<<"count_0_in_bs12 = "<<bs12.size()-bs12.count()<<"\n";              // output : 21 
    cout<<"count_0_in_bs13 = "<<bs13.size()-bs13.count()<<"\n";              // output : 23 
    cout<<"count_0_in_bs14 = "<<bs14.size()-bs14.count()<<"\n\n";              // output : 24 
    
    
    // any() - This function returns true, if atleast 1 bit is set in the bitset
	if (!bs.any()) 
	cout << "bs has no bit set.\n";					// output : bs has no bit set.
	else
	cout << "bs has atleast 1 bit set.\n";
	
	if (!bs1.any()) 
	cout << "bs1 has no bit set.\n";
	else
	cout << "bs1 has atleast 1 bit set.\n";				// output : bs1 has atleast 1 bit set.
	
	if (!bs2.any()) 
	cout << "bs2 has no bit set.\n";
	else
	cout << "bs2 has atleast 1 bit set.\n";				// output bs2 has atleast 1 bit set.
	
	
	// none() - This function returns true, if none of the bit is set 
	if (!bs.none()) 
		cout << "bs has some bit set\n";
	else
		cout << "bs has not any bit set\n";					// output : bs has not any bit set
		
	if (!bs1.none()) 
    	cout << "bs1 has some bit set\n";				// output : bs1 has some bit set
	else
		cout << "bs1 has not any bit set\n";
		
	if (!bs2.none()) 
		cout << "bs2 has some bit set\n\n";				// output : bs2 has some bit set
	else
		cout << "bs2 has not any bit set\n";
	    
	    
	// set() - This function will set all the bits of the bitset 
	cout << "bs.set() = "<<bs.set() << "\n";              // output : 111111111111111111111111111111 
	cout << "bs1.set() = "<<bs1.set() << "\n";              // output : 111111111111111111111111111111 
	cout << "bs2.set() = "<<bs2.set() << "\n";              // output : 111111111111111111111111111111 
	cout << "bs3.set() = "<<bs3.set() << "\n";              // output : 111111111111111111111111111111 
	cout << "bs4.set() = "<<bs4.set() << "\n";              // output : 111111111111111111111111111111 
	cout << "bs5.set() = "<<bs5.set() << "\n";              // output : 111111111111111111111111111111 
	cout << "bs6.set() = "<<bs6.set() << "\n";              // output : 111111111111111111111111111111 
	cout << "bs7.set() = "<<bs7.set() << "\n";              // output : 111111111111111111111111111111 
	cout << "bs8.set() = "<<bs8.set() << "\n";              // output : 111111111111111111111111111111 
	cout << "bs9.set() = "<<bs9.set() << "\n";              // output : 111111111111111111111111111111 
	cout << "bs10.set() = "<<bs10.set() << "\n";            // output : 111111111111111111111111111111 
	cout << "bs11.set() = "<<bs11.set() << "\n";            // output : 111111111111111111111111111111 
	cout << "bs12.set() = "<<bs12.set() << "\n";            // output : 111111111111111111111111111111 
	cout << "bs13.set() = "<<bs13.set() << "\n";            // output : 111111111111111111111111111111 
	cout << "bs14.set() = "<<bs14.set() << "\n\n";          // output : 111111111111111111111111111111 
	
	
	// bs.set(index, b) makes bs[index] = b ( from right most side. Means, here 0th index will be right most bit)
	cout << "bs.set(4, 0) = "<<bs.set(4,0) << "\n";              // output : 111111111111111111111111101111 
	cout << "bs1.set(4, 0) = "<<bs1.set(4,0) << "\n";              // output : 111111111111111111111111101111 
	cout << "bs2.set(4, 0) = "<<bs2.set(4,0) << "\n";              // output : 111111111111111111111111101111 
	cout << "bs3.set(4, 0) = "<<bs3.set(4,0) << "\n";              // output : 111111111111111111111111101111 
	cout << "bs4.set(4, 0) = "<<bs4.set(4,0) << "\n";              // output : 111111111111111111111111101111 
	cout << "bs5.set(4, 0) = "<<bs5.set(4,0) << "\n";              // output : 111111111111111111111111101111 
	cout << "bs6.set(4, 0) = "<<bs6.set(4,0) << "\n";              // output : 111111111111111111111111101111 
	cout << "bs7.set(4, 0) = "<<bs7.set(4,0) << "\n";              // output : 111111111111111111111111101111 
	cout << "bs8.set(4, 0) = "<<bs8.set(4,0) << "\n";              // output : 111111111111111111111111101111 
	cout << "bs9.set(4, 0) = "<<bs9.set(4,0) << "\n";              // output : 111111111111111111111111101111 
	cout << "bs10.set(4, 0) = "<<bs10.set(4,0) << "\n";            // output : 111111111111111111111111101111 
	cout << "bs11.set(4, 0) = "<<bs11.set(4,0) << "\n";            // output : 111111111111111111111111101111 
	cout << "bs12.set(4, 0) = "<<bs12.set(4,0) << "\n";            // output : 111111111111111111111111101111 
	cout << "bs13.set(4, 0) = "<<bs13.set(4,0) << "\n";            // output : 111111111111111111111111101111 
	cout << "bs14.set(4, 0) = "<<bs14.set(4,0) << "\n\n";          // output : 111111111111111111111111101111 
	
	
	// bs.set(index) makes bs[index] = 1 i.e. default is 1 
	cout << "bs.set(4) = "<<bs.set(4) << "\n";               // output : 111111111111111111111111111111 
	cout << "bs1.set(4) = "<<bs1.set(4) << "\n";               // output : 111111111111111111111111111111 
	cout << "bs2.set(4) = "<<bs2.set(4) << "\n";               // output : 111111111111111111111111111111 
	cout << "bs3.set(4) = "<<bs3.set(4) << "\n";               // output : 111111111111111111111111111111 
	cout << "bs4.set(4) = "<<bs4.set(4) << "\n";               // output : 111111111111111111111111111111 
	cout << "bs5.set(4) = "<<bs5.set(4) << "\n";               // output : 111111111111111111111111111111 
	cout << "bs6.set(4) = "<<bs6.set(4) << "\n";               // output : 111111111111111111111111111111 
	cout << "bs7.set(4) = "<<bs7.set(4) << "\n";               // output : 111111111111111111111111111111 
	cout << "bs8.set(4) = "<<bs8.set(4) << "\n";               // output : 111111111111111111111111111111 
	cout << "bs9.set(4) = "<<bs9.set(4) << "\n";               // output : 111111111111111111111111111111 
	cout << "bs10.set(4) = "<<bs10.set(4) << "\n";               // output : 111111111111111111111111111111 
	cout << "bs11.set(4) = "<<bs11.set(4) << "\n";               // output : 111111111111111111111111111111 
	cout << "bs12.set(4) = "<<bs12.set(4) << "\n";               // output : 111111111111111111111111111111 
	cout << "bs13.set(4) = "<<bs13.set(4) << "\n";               // output : 111111111111111111111111111111 
	cout << "bs14.set(4) = "<<bs14.set(4) << "\n\n";              // output : 111111111111111111111111111111 
	
	
	// reset(index) - This function makes bs[index] to 0 i.e., 
	// this function will reset the value of bs[index] to 0
	cout << "bs.reset(2) = "<< bs.reset(2) << "\n";              // output : 111111111111111111111111111011 
	cout << "bs1.reset(2) = "<< bs1.reset(2) << "\n";              // output : 111111111111111111111111111011 
	cout << "bs2.reset(2) = "<< bs2.reset(2) << "\n";              // output : 111111111111111111111111111011 
	cout << "bs3.reset(2) = "<< bs3.reset(2) << "\n";              // output : 111111111111111111111111111011 
	cout << "bs4.reset(2) = "<< bs4.reset(2) << "\n";              // output : 111111111111111111111111111011 
	cout << "bs5.reset(2) = "<< bs5.reset(2) << "\n";              // output : 111111111111111111111111111011 
	cout << "bs6.reset(2) = "<< bs6.reset(2) << "\n";              // output : 111111111111111111111111111011 
	cout << "bs7.reset(2) = "<< bs7.reset(2) << "\n";              // output : 111111111111111111111111111011 
	cout << "bs8.reset(2) = "<< bs8.reset(2) << "\n";              // output : 111111111111111111111111111011 
	cout << "bs9.reset(2) = "<< bs9.reset(2) << "\n";              // output : 111111111111111111111111111011 
	cout << "bs10.reset(2) = "<< bs10.reset(2) << "\n";              // output : 111111111111111111111111111011 
	cout << "bs11.reset(2) = "<< bs11.reset(2) << "\n";              // output : 111111111111111111111111111011 
	cout << "bs12.reset(2) = "<< bs12.reset(2) << "\n";               // output : 111111111111111111111111111011 
	cout << "bs13.reset(2) = "<< bs13.reset(2) << "\n";              // output : 111111111111111111111111111011 
	cout << "bs14.reset(2) = "<< bs14.reset(2) << "\n\n";              // output : 111111111111111111111111111011 
	
	
	// reset() - This function makes all bits 0 of the bitset
	cout << "bs.reset() = "<< bs.reset() << "\n";              // output : 000000000000000000000000000000 
	cout << "bs1.reset() = "<< bs1.reset() << "\n";              // output : 000000000000000000000000000000 
	cout << "bs2.reset() = "<< bs2.reset() << "\n";              // output : 000000000000000000000000000000 
	cout << "bs3.reset() = "<< bs3.reset() << "\n";              // output : 000000000000000000000000000000 
	cout << "bs4.reset() = "<< bs4.reset() << "\n";              // output : 000000000000000000000000000000 
	cout << "bs5.reset() = "<< bs5.reset() << "\n";              // output : 000000000000000000000000000000 
	cout << "bs6.reset() = "<< bs6.reset() << "\n";              // output : 000000000000000000000000000000 
	cout << "bs7.reset() = "<< bs7.reset() << "\n";              // output : 000000000000000000000000000000 
	cout << "bs8.reset() = "<< bs8.reset() << "\n";              // output : 000000000000000000000000000000 
	cout << "bs9.reset() = "<< bs9.reset() << "\n";              // output : 000000000000000000000000000000 
	cout << "bs10.reset() = "<< bs10.reset() << "\n";              // output : 000000000000000000000000000000 
	cout << "bs11.reset() = "<< bs11.reset() << "\n";              // output : 000000000000000000000000000000 
	cout << "bs12.reset() = "<< bs12.reset() << "\n";              // output : 000000000000000000000000000000 
	cout << "bs13.reset() = "<< bs13.reset() << "\n";              // output : 000000000000000000000000000000 
	cout << "bs14.reset() = "<< bs14.reset() << "\n\n";              // output : 000000000000000000000000000000 
	
	
	// flip() - This function  flips all bits of the bitset i.e. 1 <-> 0 
	cout << "bs.flip() = "<< bs.flip() << "\n";               // output : 111111111111111111111111111111 
	cout << "bs1.flip() = "<< bs1.flip() << "\n";               // output : 111111111111111111111111111111 
	cout << "bs2.flip() = "<< bs2.flip() << "\n";               // output : 111111111111111111111111111111 
	cout << "bs3.flip() = "<< bs3.flip() << "\n";               // output : 111111111111111111111111111111 
	cout << "bs4.flip() = "<< bs4.flip() << "\n";               // output : 111111111111111111111111111111 
	cout << "bs5.flip() = "<< bs5.flip() << "\n";               // output : 111111111111111111111111111111 
	cout << "bs6.flip() = "<< bs6.flip() << "\n";               // output : 111111111111111111111111111111 
	cout << "bs7.flip() = "<< bs7.flip() << "\n";               // output : 111111111111111111111111111111 
	cout << "bs8.flip() = "<< bs8.flip() << "\n";               // output : 111111111111111111111111111111 
	cout << "bs9.flip() = "<< bs9.flip() << "\n";               // output : 111111111111111111111111111111 
	cout << "bs10.flip() = "<< bs10.flip() << "\n";               // output : 111111111111111111111111111111 
	cout << "bs11.flip() = "<< bs11.flip() << "\n";               // output : 111111111111111111111111111111 
	cout << "bs12.flip() = "<< bs12.flip() << "\n";               // output : 111111111111111111111111111111 
	cout << "bs13.flip() = "<< bs13.flip() << "\n";              // output : 111111111111111111111111111111 
	cout << "bs14.flip() = "<< bs14.flip() << "\n\n";              // output : 111111111111111111111111111111 
	
	
	// flip(index) - This function flips the bit of bs[index] i.e., 1 <-> 0
	cout << "bs.flip(6) = "<< bs.flip(6) << "\n";              // output : 111111111111111111111110111111 
	cout << "bs1.flip(6) = "<< bs1.flip(6) << "\n";              // output : 111111111111111111111110111111 
	cout << "bs2.flip(6) = "<< bs2.flip(6) << "\n";              // output : 111111111111111111111110111111 
	cout << "bs3.flip(6) = "<< bs3.flip(6) << "\n";              // output : 111111111111111111111110111111 
	cout << "bs4.flip(6) = "<< bs4.flip(6) << "\n";              // output : 111111111111111111111110111111 
	cout << "bs5.flip(6) = "<< bs5.flip(6) << "\n";              // output : 111111111111111111111110111111 
	cout << "bs6.flip(6) = "<< bs6.flip(6) << "\n";              // output : 111111111111111111111110111111 
	cout << "bs7.flip(6) = "<< bs7.flip(6) << "\n";              // output : 111111111111111111111110111111 
	cout << "bs8.flip(6) = "<< bs8.flip(6) << "\n";              // output : 111111111111111111111110111111 
	cout << "bs9.flip(6) = "<< bs9.flip(6) << "\n";              // output : 111111111111111111111110111111 
	cout << "bs10.flip(6) = "<< bs10.flip(6) << "\n";              // output : 111111111111111111111110111111 
	cout << "bs11.flip(6) = "<< bs11.flip(6) << "\n";              // output : 111111111111111111111110111111 
	cout << "bs12.flip(6) = "<< bs12.flip(6) << "\n";              // output : 111111111111111111111110111111 
	cout << "bs13.flip(6) = "<< bs13.flip(6) << "\n";              // output : 111111111111111111111110111111 
	cout << "bs14.flip(6) = "<< bs14.flip(6) << "\n";              // output : 111111111111111111111110111111 
	
	
	// Converting decimal number x to binary by using bitset<N>(x) 
	int num1 = 24; 
	cout << "\n Binary equivalent of 24: " << bitset<30>(num1);              // output : 000000000000000000000000011000 
	
	int num2 = 36; 
	cout << "\n Binary equivalent of 36: " << bitset<30>(num2);              // output : 000000000000000000000000100100 
	
	int num3 = 56; 
	cout << "\n Binary equivalent of 56: " << bitset<30>(num3);              // output : 000000000000000000000000111000 
	
	cout<<"\n\n";
	
	
	// Let's see some applicable operators on bitset in C++
	
	/*
	For bitset, all bitwise operator are overloaded that is they can be applied 
	to bitset directly without any casting or conversion, main overloaded 
	operator are &, |, ==, != and shifting operator <> which makes operation 
	on bitset easy. Use of above operator is shown in below code.
    */
    
	bitset<4> bset1(9); // bset1 contains 1001 
    bitset<4> bset2(3); // bset2 contains 0011 
  
    // comparison operator 
    cout << (bset1 == bset2) << endl; // false 0 
    cout << (bset1 != bset2) << endl; // true  1 
  
    // bitwise operation and assignment 
    cout << (bset1 ^= bset2) << endl; // 1010 
    cout << (bset1 &= bset2) << endl; // 0010 
    cout << (bset1 |= bset2) << endl; // 0011 
  
    // left and right shifting 
    cout << (bset1 <<= 2) << endl; // 1100 
    cout << (bset1 >>= 1) << endl; // 0110 
  
    // not operator 
    cout << (~bset2) << endl; // 1100 
  
    // bitwise operator 
    cout << (bset1 & bset2) << endl; // 0010 
    cout << (bset1 | bset2) << endl; // 0111 
    cout << (bset1 ^ bset2) << endl; // 0101 
}


// -----------------------------------------------------------------------------


// Problem Link: https://practice.geeksforgeeks.org/problems/binary-representation5003/1/?

string getBinaryRep(int N)
{
	string str = "";
	
	// this loop will run exactly 30 times ( not 29 times ) because we are checking value of i>0. So, it will iterate till i = 2^0 = 1>0.
	for(long int i=1<<29;i>0;i=i/2)			// this is very useful ( think about it ) - N will be perfect power of 2 everytime.
	{
	    if(N&i)
		str += "1";
	    else
		str += "0";
	}
	return str;
}
