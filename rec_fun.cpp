//
//  main.cpp
//  DS Proj 5
//
//  Created by Emma Athow on 4/01/20.
//  Copyright © 2020 Emma Athow. All rights reserved.
//
#include <iostream>
#include <cstdlib>
#include <cassert>
using namespace std;
//Write a function with this prototype:
//void binary_print(ostream& outs, unsigned int n);
//The function prints the value of n as a BINARY number to the ostream outs. If n is zero, then a single zero is printed; otherwise no leading zeros are printed in the output. The ‘\n’ character is NOT printed at the end of the output.
//EXAMPLES:
// n=0  Output:0
// n=4  Output:100
// n=27 Output:11011

void binary_print(ostream& outs, unsigned int n) {
    if(n < 2){
        outs << n;
    }
    else {
        binary_print(outs, n/2);
        outs << n % 2;
    }
}

//Triangle Pattern
//void triangle(ostream& outs, unsigned int m, unsigned int n)
// Precondition: m <= n
// Postcondition: The function has printed a pattern of 2*(n-m+1) lines
// to the output stream outs. The first line contains m asterisks, the next
// line contains m+1 asterisks, and so on up to a line with n asterisks.
// Then the pattern is repeated backwards, going n back down to m.
/* Example output:
   triangle(cout, 3, 5) will print this to cout:
   ***
   ****
   *****
   *****
   ****
   ***
*/
//Hint: Only one of the arguments changes in the recursive call. Which one?

void triangle(ostream& outs, unsigned int m, unsigned int n) {
    if(m <= n) {
        for(int i = 0; i < m; i++) {
            cout << '*';
        }
        cout << endl;
        triangle(cout, m + 1, n);
        for(int i = 0; i < m; i++) {
            cout << '*';
        }
        cout << endl;
    }
}

//Pow Function (Project 13, page 452)
//Rewrite the recursive pow function from Fig. 9.10 on page 445, so that the time to compute pow(x,n) is log(n):
// double pow(double x, int n);
   // Precondition: If x is zero, then n must be positive.
   // Postcondition: The value returned is x raised to the power n.
//Hint: use the formula x^2n = x^n  x^n

double power(double x, int n) {
    if(n == 0){
        return 1;
    }
    else if(n % 2 == 0) {
        return power(x, n/2) * power(x, n/2);
    }
    else {
        return x * power(x, n/2) * power(x, n/2);
    }
}

//Repeated and Indented Sentences (Project 1, page 450)
//Write a  function that produces output like the following:
//This was written by calling number 1.
//  This was written by calling number 2.
//   This was written by calling number 3.
//      This was written by calling number 4.
//      This was ALSO written by calling number 4.
//    This was ALSO written by calling number 3.
//  This was ALSO written by calling number 2.
//This was ALSO written by calling number 1.
//In the above example, the recursion stopped when it reached four levels deep, but your function should be capable of continuing any specific level with the following function prototype.
//void indented_sentences(size_t m, size_t n);
// precondition: m <=n;
//postcondition: print out the above pattern by calling number from m to n

void indented_sentences(size_t m, size_t n) {
    if(m <= n) {
        for(int i = 0; i < m; i++) {
            cout << ' ';
        }
        cout << "This was written by calling number " << m << endl;
        indented_sentences(m + 1, n);
        for(int i = 0; i < m; i++){
            cout << ' ';
        }
        cout << "This was ALSO written by calling number " << m << endl;
    }
}

//Main Code for above functions

int main() {
    //To check the first function
    binary_print(cout, 0);
    cout << endl;
    binary_print(cout, 4);
    cout << endl;
    binary_print(cout, 27);
    cout << endl;
    
    //To check the second function
    cout << endl;
    triangle(cout, 3, 5);
    cout << endl;
    
    //To check the third function
    cout << power(5, 3);
    cout << endl;
    
    //To check the fourth function
    cout << endl;
    indented_sentences(1,4);
    
    return 0;
}
