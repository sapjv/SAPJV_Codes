// Problem Link: https://cses.fi/problemset/task/1651/

#include<bits/stdc++.h>
using namespace std;

#define MM 200005
typedef long long int lli;

vector<int> v(MM);
vector<lli> segTree(4*MM, 0);
vector<lli> lazy(4*MM, 0);

void buildTree(int index, int s, int e){
    if(s==e){
        segTree[index] = v[s];
        return;
    }
    int mid = (s+e)>>1;
    buildTree(2*index+1, s, mid);
    buildTree(2*index+2, mid+1, e);
    segTree[index] = segTree[2*index+1] + segTree[2*index+2];
}

void updateRange(int index, int s, int e, int L, int R, lli value){
    if(lazy[index]!=0){
        segTree[index] += (e-s+1)*lazy[index];
        if(s!=e){
            lazy[2*index+1] += lazy[index];
            lazy[2*index+2] += lazy[index];
        }
        lazy[index] = 0;
    }
    if(s>e || s>R || e<L){
        return;
    }
    if(s>=L && e<=R){
        segTree[index] += (e-s+1)*value;
        if(s!=e){
            lazy[2*index+1] += value;
            lazy[2*index+2] += value;
        }
        return;
    }
    int mid = (s+e)>>1;
    updateRange(2*index+1, s, mid, L, R, value);
    updateRange(2*index+2, mid+1, e, L, R, value);
    segTree[index] = segTree[2*index+1] + segTree[2*index+2];
}

lli getSumQuery(int index, int s, int e, int L, int R){
    if(lazy[index]!=0){
        segTree[index] += (e-s+1)*lazy[index];
        if(s!=e){
            lazy[2*index+1] += lazy[index];
            lazy[2*index+2] += lazy[index];
        }
        lazy[index] = 0;
    }
    if(s>e || s>R || e<L){
        return 0;
    }
    if(s>=L && e<=R){
        return segTree[index];
    }
    int mid = (s+e)>>1;
    lli left = getSumQuery(2*index+1, s, mid, L, R);
    lli right = getSumQuery(2*index+2, mid+1, e, L, R);
    return left + right;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, q;
    cin>>n>>q;

    for(int i=1;i<=n;i++){
        cin>>v[i];
    }

    buildTree(1, 1, n);       // index, start, end

    while(q--){
        int type;
        cin>>type;
        if(type == 1){
            int L, R, value;
            cin>>L>>R>>value;
            updateRange(1, 1, n, L, R, value);
        } else {
            int L;
            cin>>L;
            int R = L;      // here L and R will be same because of point query
            cout << getSumQuery(1, 1, n, L, R) << "\n";
        }
    }
}
