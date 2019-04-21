/*

Functions of deque STL : 

(a) at()  OR  []
(b) size()
(c) push_back()         OR      emplace_back()
(d) push_front()        OR      emplace_front()
(e) pop_back()
(f) pop_front()
(g) clear() and erase()

*/


#include<bits/stdc++.h>
using namespace std;
int main()
{
    deque<int> dq;
    
    for(int i=1;i<=10;i++)
    dq.push_back(11*i);
    
    for(int i=0;i<dq.size();i++)
    cout<<dq[i]<<" ";
    
    cout<<"\n\n";
    
    for(int i=0;i<dq.size();i++)
    cout<<dq.at(i)<<" ";
    
    cout<<"\n\n";
    
    for(auto it=dq.begin();it!=dq.end();it++)
    cout<<*it<<" ";
    
    cout<<"\n\n";
    
    cout<<"front of deque : "<<dq.front()<<"\n";
    cout<<"end of deque : "<<dq.back()<<"\n";
    
    dq.pop_front();
    dq.pop_back();
    
    cout<<"\n";
    
    cout<<"front of deque : "<<dq.front()<<"\n";
    cout<<"end of deque : "<<dq.back()<<"\n";
}
