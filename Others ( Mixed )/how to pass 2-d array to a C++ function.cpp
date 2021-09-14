      ### How to pass 2-d array to a C++ function ###

// Example1:  https://codeforces.com/contest/724/submission/128790772

const int N1=20, M1=20;
int n,m;
bool isSorted(int temp[N1][M1]){
    for(int i=0;i<n;i++){
	for(int j=0;j<m;j++){
	    temp[i][j] *= 5;
	}
    }
}
int main(){
    cin>>n>>m;
    int temp1[N1][M1];
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin>>temp1[i][j];
        }
    }
    if(isSorted(temp1)){ 
      ....
    }
}


------------------------------------------
  
// Example2:   https://codeforces.com/contest/1162/submission/121157714
  
const int M1 = 50, N1 = 50;
int n, m;
 
bool isIncreasing(lli matrix[N1][M1]){
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            matrix[i][j] *= 5;
        }
    }
}
 
int main(){
    cin>>n>>m;
	
    lli mA[50][50];
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin>>mA[i][j];
        }
    }
	
    if(isIncreasing(mA) && isIncreasing(mB)){
        ...
    }
}
 
