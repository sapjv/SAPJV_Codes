/*

	### Number of palindromic paths in a matrix using DFS ###

Please check the DP solution for problem statement and examples.

This below solution is using DFS. In each step, we'll just move to both neighbors of current 
element ( also we'll increment the current string by adding the neighboring character to it).
 
This below solution is consuming more time than the DP one. But we may ( note this is "may", 
i am not too much sure for this ) improve the time of DFS solution by using visited array. 

*/

int n,m;
char matrix[10][10];

bool check_Palindrome(string str)
{
    string temp = str;
    reverse(all(temp));
    if(temp == str)
        return true;
    return false;
}

void dfs(int i,int j,string s,int &ans)
{
    // this is base case ( when current indices are out of range )
    if(i>=n || j>=m)
        return;
    
    // when we reach at end ( bottom right corner i.e., matrix[n-1][m-1] ) 
    if(i==n-1 && j==m-1)
    {
        s += matrix[i][j];
        if(check_Palindrome(s))
            ans++;
    }
    
    // note that we are moving to both of the neighbors of current element along with new string.
    dfs(i+1,j,s+matrix[i][j],ans);
    dfs(i,j+1,s+matrix[i][j],ans);
}

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        cin>>n>>m;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
                cin>>matrix[i][j];
        }
        
        int ans = 0;
        string s = "";
        dfs(0,0,s,ans);
        cout<<ans<<"\n";
    }
}
