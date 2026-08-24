#include <iostream>
#include <unordered_map>
using namespace std;

int main()
{
    int n;

    cout << "Enter number of elements: ";
    cin >> n;

    int a[n];

    cout << "Enter elements: ";
    for (int i = 0; i < n; i++)
        cin >> a[i];

    unordered_map<int, int> freq;

    for (int i = 0; i < n; i++)
    {
        freq[a[i]]++;
    }

    cout << "Frequency of elements:\n";

    for (auto x : freq)
    {
        cout << x.first << " : " << x.second << endl;
    }

    return 0;
}