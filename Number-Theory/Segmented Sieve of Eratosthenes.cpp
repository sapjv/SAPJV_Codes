// Note : For this program , condition is :  r-l<=8000000      
// Means this program is correctly working when L = 20000000 , R = 28000000        So , R-L = 8000000 ( 8 * 10^6)

#include<bits/stdc++.h>
using namespace std;
typedef long long int lli;
lli MAX=1000001;
vector<lli> prime;
void sieve()
{
    lli arr[MAX];
    for(lli i=0;i<MAX;i++)
    arr[i]=i;
    lli p=2;
    while(p*p<MAX)
    {
        if(arr[p])
        {
            for(lli j=p*p;j<=MAX;j+=p)
            arr[j]=0;
        }
        p++;
    }
    prime.push_back(2);
    for(lli i=3;i<MAX;i+=2)
    {
        if(arr[i]!=0)
        prime.push_back(arr[i]);
    }
}
void segmented(lli l,lli r)
{
    bool temp[r-l+1];
    for(lli i=0;i<=r-l;i++)
    {
        temp[i]=true;
    }
    if(l==1)        // when l is 1 , we'll manually make it false
    temp[0]=false;
    for(lli i=0;prime[i]*prime[i]<=r;i++)
    {
        lli current_prime=prime[i];
        // cout<<"current_prime = "<<current_prime<<"\n";
        // for just smaller or equal value to L
        lli start = (l/current_prime)*current_prime;
        if(start<l)
        start+=current_prime;
        
        // Marking all multiples of current prime within range L to R as false
        for(lli j= start;j<=r;j+=current_prime)
        temp[j-l]=false;
        
        // There may be a case where base case is itself a prime number
        if(start==current_prime)
        temp[start-l]=true;
    }
    vector<lli> result;
    for(lli i=0;i<=r-l;i++)
    {
        if(temp[i]==true)
        result.push_back(i+l);
    }
    // cout<<"result size = "<<result.size()<<"\n";
    for(lli i=0;i<result.size();i++)
    cout<<result[i]<<"\n";
    cout<<"\n";
}
int main()
{   
    sieve();
    int t;
    cin>>t;
    while(t--)
    {
        lli l,r;
        cin>>l>>r;
        segmented(l,r);
    }
}

