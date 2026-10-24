#include<iostream>

using namespace std;

int main() {

    // Fibonacci series up to n terms
    int n, t1 = 0, t2 = 1, nextTerm = 0;
    cout << "Enter the number of terms: ";

    cin >> n;

    if ( n <= 2)
    {
        cout << "enter a number >= 3!" << endl;
        return 1;
    }

    cout << t1 << ", " << t2;

    for(int i = 3; i <= n; i++)
    {
        nextTerm = t1 + t2;
        cout <<  ", " << nextTerm;

        t1 = t2;
        t2 = nextTerm;

    }
    cout << "." << endl;
 
    return 0;
}