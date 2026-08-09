#include <iostream>
using namespace std;
int main() {
    int n, key, pos = -1;
    cout << "Enter size: ";
    cin >> n;
    int a[n];
    cout << "Enter elements: ";
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    cout << "Enter element to search: ";
    cin >> key;
    for (int i = 0; i < n; i++) {
        if (a[i] == key) {
            pos = i;
            break;
        }
    }
    if (pos != -1)
        cout << "Element found at position " << pos + 1;
    else
        cout << "Element not found";
    return 0;
}
