#include <iostream>
#include <unordered_set>
using namespace std;

int main()
{
    int n, T;

    cout << "Enter number of elements: ";
    cin >> n;

    int a[n];

    cout << "Enter elements: ";
    for (int i = 0; i < n; i++)
        cin >> a[i];

    cout << "Enter target T: ";
    cin >> T;

    unordered_set<int> s;

    for (int i = 0; i < n; i++)
    {
        int needed = T - a[i];

        if (s.find(needed) != s.end())
        {
            cout << "Pair found: "
                 << needed << " + " << a[i]
                 << " = " << T << endl;

            return 0;
        }

        s.insert(a[i]);
    }

    cout << "No such pair exists." << endl;

    return 0;
}