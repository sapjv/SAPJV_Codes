/*

Power Set : Power set P(S) of a set S is the set of all subsets of S. 
For example S = {a, b, c} then P(s) = {{}, {a}, {b}, {c}, {a,b}, {a, c}, {b, c}, {a, b, c}}.

Note : If S has n elements in it, then P(S) will have 2^n elements

Algorithm:

  Input: Set[], set_size
  1. Get the size of power set
      powet_set_size = pow(2, set_size)
  2  Loop for counter from 0 to pow_set_size
       (a) Loop for i = 0 to set_size
            (i) If ith bit in counter is set :
                    then, Print ith element from set for this subset
       (b) Print separator for subsets i.e., newline

Example:

Set  = [a,b,c]
power_set_size = pow(2, 3) = 8
Run for binary counter = 000 to 111

Value of Counter            Subset
    000                    -> Empty set
    001                    -> a
    010                    -> b
    011                    -> ab
    100                    -> c
    101                    -> ac
    110                    -> bc
    111                    -> abc

*/

C++ Code for printing all the subsets ( power set ) of the array : 

int main()
{
    int arr[] = {1,2,3,4};
    
    int pow_set_size = pow(2,4);        // Please take care of overflow by yourself
  
    /*Run from counter 000..0 to 111..1*/
    for(int counter = 0; counter < pow_set_size; counter++) 
    { 
        cout<<"counter_value = "<<counter<<" , subset elements : { ";
        for(int j = 0; j < 4; j++) 
        { 
            /* Check if jth bit in the counter is set If set then print jth element from set */
            bool res = counter & (1 << j);
            if(res) 
                cout << arr[j]; 
        } 
        cout << " } \n"; 
    } 
}


/*

Output :

counter_value = 0 , subset elements : {  }
counter_value = 1 , subset elements : { 1 }
counter_value = 2 , subset elements : { 2 }
counter_value = 3 , subset elements : { 12 }
counter_value = 4 , subset elements : { 3 }
counter_value = 5 , subset elements : { 13 }
counter_value = 6 , subset elements : { 23 }
counter_value = 7 , subset elements : { 123 }
counter_value = 8 , subset elements : { 4 }
counter_value = 9 , subset elements : { 14 }
counter_value = 10 , subset elements : { 24 }
counter_value = 11 , subset elements : { 124 }
counter_value = 12 , subset elements : { 34 }
counter_value = 13 , subset elements : { 134 }
counter_value = 14 , subset elements : { 234 }
counter_value = 15 , subset elements : { 1234 }

*/
