#include <iostream>
using namespace std;

int main() {
    int n, key;
    int low, high, mid;
    int pos = -1;
    cout << "Enter size: ";
    cin >> n;
    int a[n];
    cout << "Enter sorted elements: ";
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    cout << "Enter element to search: ";
    cin >> key;
    low = 0;
    high = n - 1;
    while (low <= high) {
        mid = (low + high) / 2;
        if (a[mid] == key) {
            pos = mid;
            break;
        }
        else if (key < a[mid]) {
            high = mid - 1;
        }
        else {
            low = mid + 1;
        }
    }

    if (pos != -1)
        cout << "Element found at position " << pos + 1;
    else
        cout << "Element not found";
    return 0;
}
