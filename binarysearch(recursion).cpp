#include <iostream>
using namespace std;

int binarySearch(int a[], int low, int high, int key)
{
    if (low > high)
        return -1;
    int mid = (low + high) / 2;
    if (a[mid] == key)
        return mid;
    if (key < a[mid])
        return binarySearch(a, low, mid - 1, key);

    return binarySearch(a, mid + 1, high, key);
}
int main()
{
    int n, key, pos;
    cout << "Enter size: ";
    cin >> n;
    int a[n];

    cout << "Enter sorted elements: ";
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    cout << "Enter element to search: ";
    cin >> key;
    pos = binarySearch(a, 0, n - 1, key);
    if (pos != -1)
        cout << "Element found at position " << pos + 1;
    else
        cout << "Element not found";
    return 0;
}
