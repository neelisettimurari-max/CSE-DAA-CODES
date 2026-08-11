
#include <iostream>
#include <cmath>
using namespace std;
int main()
{
    double x;
    int n;
    cout << "Enter value of X: ";
    cin >> x;
    cout << "Enter number of terms: ";
    cin >> n;

    double sum;
    if (x == 1)
    {
        sum = n;
    }
    else
    {
        sum = (pow(x, n) - 1) / (x - 1);
    }
    cout << "Sum of the series = " << sum << endl;
    return 0;
}

