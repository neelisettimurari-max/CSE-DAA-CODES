#include <iostream>
#include <queue>
using namespace std;

int main()
{
    int n, k;

    cout << "Enter size of array: ";
    cin >> n;

    int a[n];

    cout << "Enter array elements: ";

    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }

    cout << "Enter K: ";
    cin >> k;

    if (k < 1 || k > n)
    {
        cout << "Invalid K";
        return 0;
    }

    priority_queue<int, vector<int>, greater<int>> minHeap;

    for (int i = 0; i < n; i++)
    {
        minHeap.push(a[i]);
    }

    int answer = 0;

    for (int i = 0; i < k; i++)
    {
        answer = minHeap.top();
        minHeap.pop();
    }

    cout << "Kth smallest element = " << answer << endl;

    return 0;
}