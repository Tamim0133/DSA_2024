// C++ program to calculate Nth root of a number
#include <bits/stdc++.h>
using namespace std;

// method returns Nth power of A
double nthRoot(int A, int N)
{
    // initially guessing a random number between
    // 0 and 9
    double xPre = rand() % 10;

    // smaller eps, denotes more accuracy
    double eps = 1e-3;

    // initializing difference between two
    // roots by INT_MAX
    double delX = INT_MAX;

    // xK denotes current value of x
    double xK;

    // loop until we reach desired accuracy
    while (delX > eps)
    {
        // calculating current value from previous
        // value by newton's method
        xK = ((N - 1.0) * xPre +
              (double)A / pow(xPre, N - 1)) /
             (double)N;
        delX = abs(xK - xPre);
        xPre = xK;
    }

    return xK;
}

// Driver code to test above methods
int main()
{
    int N = 2;
    int A = 226;

    double nthRootValue = nthRoot(A, N);
    cout << "Nth root is " << nthRootValue << endl;

    /*
        double Acalc = pow(nthRootValue, N);
        cout << "Error in difference of powers "
            << abs(A - Acalc) << endl;
    */

    return 0;
}
