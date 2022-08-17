#include<bits/stdc++.h>
using namespace std;

#define MM 200005
typedef long long int lli;

vector<int> v(MM);
vector<lli> segTree(4*MM, 0);

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

lli query(int index, int s, int e, int L, int R){
    if(L<=s && e<=R){
        return segTree[index];
    }
    if(e<L || R<s){
        return 0;
    }
    int mid = (s+e)>>1;
    lli left = query(2*index+1, s, mid, L, R);
    lli right = query(2*index+2, mid+1, e, L, R);
    return left + right;
}

void update(int index, int s, int e, int pos, int value){
    if(pos<s || pos>e){
        return;
    }
    if(s==e){
        segTree[index] = value;
        return;
    }
    int mid = (s+e)>>1;
    update(2*index+1, s, mid, pos, value);
    update(2*index+2, mid+1, e, pos, value);
    segTree[index] = segTree[2*index+1] + segTree[2*index+2];
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
            int pos, value;
            cin>>pos>>value;
            update(1, 1, n, pos, value);
        } else {
            int L, R;
            cin>>L>>R;
            cout << query(1, 1, n, L, R) << "\n";
        }
    }
}

