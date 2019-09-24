// Bitmasking - NR2 Spoj ( Use of Bitwise Operators - ~ , | , & )

#include<bits/stdc++.h>
using namespace std;
typedef long long int lli;

#define M 10001
#define MOD 1000000007
#define ep emplace_back

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

// 	freopen("input.txt", "rt", stdin);
 	
 	int n;
 	cin>>n;
 	
// 	cout<<~(15)<<"\n";
// 	cout<<~(17)<<"\n";
 	
// 	int e1 = 10 & ( ~(15) | ~(17));
// 	int e2 = ~(10) & (15 | 17);
// 	int e3 = 15 & (~(17));
// 	int e4 = ~15 & (17);
 	
// 	cout<<"E1 = "<<e1<<"  E2 = "<<e2 <<"  E3 = "<<e3<<"  E4 = "<<e4<<"\n";
	  
 	lli a[n+1];
 	for(int i=1;i<=n;i++)
 	cin>>a[i];
 	
 	lli not_or_a[n+1] , or_a[n+1];
 	
 	not_or_a[n] = ~(a[n]);
 	or_a[n] = (a[n]);
 	
 	for(int i=n-1;i>=2;i--)
 	{
 		not_or_a[i] = not_or_a[i+1] | (~(a[i]));
 		or_a[i] = or_a[i+1] | a[i];
	}
	
	lli res = 0;
	for(int i=1;i<=n-1;i++)
	{
		lli exp1 = ( a[i] & not_or_a[i+1] );
		lli exp2 = (~(a[i]) & or_a[i+1]);
//		cout<<"\nexp1 = "<<exp1<<"  exp2 = "<<exp2<<"\n";
		res = res | (exp1 | exp2);
	}
	
	cout<<res<<"\n";
 	
}   
