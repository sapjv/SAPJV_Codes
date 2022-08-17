#include<bits/stdc++.h>
using namespace std;

#define MM 200005

vector<int> v(MM);
vector<int> segTree(4*MM);

void buildTree(int index, int s, int e){
    if(s==e){
        segTree[index] = v[s];
        return;
    }
    int mid = (s+e)>>1;
    buildTree(2*index+1, s, mid);
    buildTree(2*index+2, mid+1, e);
    segTree[index] = min(segTree[2*index+1], segTree[2*index+2]);
}

void update(int index, int s, int e, int pos, int value){
    if(pos>e || pos<s){     // this is important
        return;
    }
    if(s==e){
        segTree[index] = value;
        return;
    }
    int mid = (s+e)>>1;
    update(2*index+1, s, mid, pos, value);
    update(2*index+2, mid+1, e, pos, value);
    segTree[index] = min(segTree[2*index+1], segTree[2*index+2]);
}

int query(int index, int s, int e, int L, int R){
    if(L<=s && e<=R){
        return segTree[index];
    }
    if(L>e || R<s){
        return INT_MAX;
    }
    int mid = (s+e)>>1;
    int left = query(2*index+1, s, mid, L, R);
    int right = query(2*index+2, mid+1, e, L, R);
    return min(left, right);
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
