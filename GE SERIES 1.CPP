#include <iostream>
using namespace std;
int main()
{
    int x, n;
    long long sum = 0;
    long long term = 1;
    cout << "Enter value of X: ";
    cin >> x;
    cout << "Enter number of terms: ";
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        sum = sum + term;
        term = term * x;
    }
    cout << "Sum of the series = " << sum << endl;

    return 0;
} 
