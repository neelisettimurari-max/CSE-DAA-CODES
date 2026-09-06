#include <iostream>
#include <climits>
using namespace std;

int maxCrossingSum(int a[], int low, int mid, int high) {
    int leftSum = INT_MIN;
    int rightSum = INT_MIN;
    int sum = 0;

    for (int i = mid; i >= low; i--) {
        sum += a[i];

        if (sum > leftSum)
            leftSum = sum;
    }

    sum = 0;

    for (int i = mid + 1; i <= high; i++) {
        sum += a[i];

        if (sum > rightSum)
            rightSum = sum;
    }

    return leftSum + rightSum;
}

int maxSubarray(int a[], int low, int high) {
    if (low == high)
        return a[low];

    int mid = (low + high) / 2;

    int left = maxSubarray(a, low, mid);
    int right = maxSubarray(a, mid + 1, high);
    int cross = maxCrossingSum(a, low, mid, high);

    return max(left, max(right, cross));
}

int main() {
    int n;

    cout << "Enter number of elements: ";
    cin >> n;

    int a[n];

    cout << "Enter elements: ";
    for (int i = 0; i < n; i++)
        cin >> a[i];

    int result = maxSubarray(a, 0, n - 1);

    cout << "Maximum subarray sum = " << result << endl;

    return 0;
} 