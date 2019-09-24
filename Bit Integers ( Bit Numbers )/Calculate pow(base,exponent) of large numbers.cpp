#include <bits/stdc++.h>
using namespace std;
typedef long long int lli;

#define MAX 250

int multiply(int x , int result[] , int res_size)
{
    int carry=0;
    
    for(int i=0;i<res_size;i++)
    {
        int product = x*result[i]+carry;
        result[i]=product%10;
        carry=product/10;
    }
    
    while(carry!=0)
    {
        result[res_size]=carry%10;
        carry = carry/10;
        res_size++;
    }
    
    return res_size;
}

void Calculate_power(int base,int exponent)
{
    int temp=base;
    int result[MAX];
    int res_size=0;
    
    while(temp!=0)
    {
        result[res_size]=temp%10;
        temp/=10;
        res_size++;
    }
    
    for(int i=0;i<exponent-1;i++)
        res_size = multiply(base,result,res_size);
        
    for(int i=res_size-1;i>=0;i--)                  // printing result in reverse order
    cout<<result[i];
    
    cout<<"\n";
}
int main() 
{
	int t;
	cin>>t;
	while(t--)
	{
	    int base,exponent;
	    cin>>base>>exponent;
	    Calculate_power(base,exponent);
	}
}

