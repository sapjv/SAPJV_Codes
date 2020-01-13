/*

Problem Link : https://www.spoj.com/problems/ORDERSET/  ( solved )
    
Useful Link : 
1. https://www.geeksforgeeks.org/policy-based-data-structures-g/
2. https://www.geeksforgeeks.org/order_of_key-in-c/
    
Policy based data structures in g++
The g++ compiler also supports some data structures that are not part of the C++ standard library. 
Such structures are called policy-based data structures. These data structures are designed for 
high-performance, flexibility, semantic safety, and conformance to the corresponding containers in std.

To use these structures, the following lines must be added to the code:

#include <ext/pb_ds/assoc_container.hpp> 
using namespace __gnu_pbds; 

For an example following is a code showing a policy-based data structure that is like set, it can 
add/remove elements, can find the number of elements less than x, kth smallest element etc in O(logn) 
time. It can also be indexed like an array. The specialty of this set is that we have access to the 
indices that the elements would have in a sorted array. If the element does not appear in the set, we 
get the position that the element would have in the set.
    
NOTE:Both the functions order_of_key and find_by_order work in logarithmic time.

---------------------

order_of_key() in C++
The order_of_key() is a builtin function of Ordered Set which is a Policy Based Data Structure in C++. 
Policy-based data structures are not part of the C++ standard library but g++ compiler supports them.

Ordered set is a policy based data structure in g++ that keeps the unique elements in sorted order. It 
performs all the operations as performed by the set data structure in STL in log(n) complexity and 
performs two additional operations also in log(n) complexity .

Two important operations that we can perform in these data structures:

1. order_of_key: The number of items in a set that are strictly smaller than k
2. find_by_order: It returns an iterator to the ith largest element

The order_of_key() function accepts a key and returns the number of elements in the ordered set which 
are strictly less than the key passed to it as a parameter.

For example,

Let us assume we have a set s : {1, 5, 6, 17, 88}, then :
s.order_of_key(6) : Count of elements strictly smaller than 6 is 2.
s.order_of_key(25) : Count of elements strictly smaller than 25 is 4.

--------------------

Comparison with lower_bound() and distance() : 

In C++ we have std::distance which takes two iterators and calculates the distance between them. i.e The 
number of elements between them. It can be an alternative for find_by_order but it’s time complexity is 
O(n) for an ordered set. lower_bound is also an option and it takes log(n) amount of time. It returns an 
iterator to the first element which is not less than k. But since it returns an iterator we can never 
know the index or number of elements which are smaller than k. For vectors and linear data structures, 
one can perform :

index = lower_bound(k) – myvector.begin() ;

But since set is a tree based data structure, we cannot perform this operation.

Below program illustrate the implementation of order_of_key():

*/

#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp> 
#include <ext/pb_ds/tree_policy.hpp> 

using namespace std;
using namespace __gnu_pbds;

typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> pbds;

int main()
{
    pbds A;

    //Add elements in any random order
    A.insert(11);
    A.insert(1);
    A.insert(5);
    A.insert(3);
    A.insert(7);
    A.insert(9);

    //Total contents
    cout << "1, 3, 5, 7, 9, 11" << endl;

    //K-th smallest
    int k = 3;
    cout << k << "rd smallest: " << *A.find_by_order(k-1) << endl;

    k = 5;
    cout << k << "th smallest: " << *A.find_by_order(k-1) << endl;

    cout<<"Size of A : "<<A.size()<<"\n";

    //NO OF ELEMENTS < X
    int X = 9;

    cout << "No of elements less than " << X << " are " << A.order_of_key(X) << endl;

    // number 7 not in the set but it will show the index number if it was there in sorted array. 
    cout << "The index of number 7 : "<< A.order_of_key(7) << endl;             // This is important
    
    //DELETE Elements
    cout << "Deleted 3" << endl;
    A.erase(3);

    //Total contents
    cout << "1, 5, 7, 9, 11" << endl;

    cout << "No of elements less than " << X << " are " << A.order_of_key(X) << endl;

    //NEXT BIGGER/SMALLER ELEMENT than X
    X = 8;

    cout << "Next greater element than " << X << " is " << *A.upper_bound(X) << endl;

    cout<<"Size of A : "<<A.size()<<"\n";

    return 0;
}

/*

Output :

1, 3, 5, 7, 9, 11
3rd smallest: 5
5th smallest: 9
Size of A : 6
No of elements less than 9 are 4
The index of number 7 : 3
Deleted 3
1, 5, 7, 9, 11
No of elements less than 9 are 3
Next greater element than 8 is 9
Size of A : 5

*/
