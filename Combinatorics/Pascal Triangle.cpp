
/*

    ### Pascal’s triangle ###

Pascal's Triangle is a triangle of numbers where each number is the two numbers directly above
it added together (except for the edges, which are all "1").

Pascal’s triangle, in algebra, a triangular arrangement of numbers that gives the coefficients
in the expansion of any binomial expression, such as (x + y)^n.

Pascal’s triangle is a triangular array of the binomial coefficients.

Question: Write a function that takes an integer value n as input and prints first n lines
of the Pascal’s triangle. Following are the first 6 rows of Pascal’s Triangle.

1
1 1
1 2 1
1 3 3 1
1 4 6 4 1
1 5 10 10 5 1


Method 1 ( O(n^3) time complexity ):
Number of entries in every line is equal to line number. For example, the first line has “1”, the
second line has “1 1”, the third line has “1 2 1”,.. and so on. Every entry in a line is value of
a Binomial Coefficient. The value of ith entry in line number line is C(line, i). The value can be
calculated using following formula.

C(line, i)   = line! / ( (line-i)! * i! )
A simple method is to run two loops and calculate the value of Binomial Coefficient C(n,k) in inner loop.

Auxiliary Space: O(1)

Time complexity of this method is O(n^3)

-------------------------------

Method 2( O(n^2) time and O(n^2) extra space ): If we take a closer at the triangle, we observe that
every entry is sum of the two values above it. So we can create a 2D array that stores previously
generated values. To generate a value in a line, we can use the previously stored values from array.

Check Image here:  https://media.geeksforgeeks.org/wp-content/uploads/pascaltriangle.png

*/


#include <iostream>
using namespace std;

void pascal(int maxn){
    int C[maxn + 1][maxn + 1];
    C[0][0] = 1;
    for (int n = 1; n <= maxn; ++n) {
        C[n][0] = C[n][n] = 1;
        for (int k = 1; k < n; ++k){
            C[n][k] = C[n - 1][k - 1] + C[n - 1][k];
        }
    }

    // This is just for printing the pascal's triangle
    for(int n=0;n<=maxn;n++){
        for(int k=0;k<=n;k++){
            cout << C[n][k] << " ";
        }
        cout << "\n";
    }
}

int main() {
    int n = 10;
    pascal(n);
}

/*

Output:

1
1 1
1 2 1
1 3 3 1
1 4 6 4 1
1 5 10 10 5 1
1 6 15 20 15 6 1
1 7 21 35 35 21 7 1
1 8 28 56 70 56 28 8 1
1 9 36 84 126 126 84 36 9 1
1 10 45 120 210 252 210 120 45 10 1

*/
