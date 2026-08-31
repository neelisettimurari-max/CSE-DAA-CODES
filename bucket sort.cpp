#include <iostream>
#include <vector>
using namespace std;

void insertionSort(vector<int>& bucket)
{
    for (int i = 1; i < bucket.size(); i++)
    {
        int key = bucket[i];
        int j = i - 1;

        while (j >= 0 && bucket[j] > key)
        {
            bucket[j + 1] = bucket[j];
            j--;
        }

        bucket[j + 1] = key;
    }
}

void bucketSort(int arr[], int n)
{
    int maxValue = arr[0];

    for (int i = 1; i < n; i++)
    {
        if (arr[i] > maxValue)
            maxValue = arr[i];
    }

    // Create n buckets
    vector<vector<int>> buckets(n);

    // Put elements into buckets
    for (int i = 0; i < n; i++)
    {
        int index = (arr[i] * n) / (maxValue + 1);

        if (index >= n)
            index = n - 1;

        buckets[index].push_back(arr[i]);
    }

    // Sort individual buckets
    for (int i = 0; i < n; i++)
    {
        insertionSort(buckets[i]);
    }

    // Combine buckets
    int k = 0;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < buckets[i].size(); j++)
        {
            arr[k] = buckets[i][j];
            k++;
        }
    }
}

int main()
{
    int n;
    int arr[100];

    cout << "Enter number of elements: ";
    cin >> n;

    cout << "Enter non-negative elements: ";
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    bucketSort(arr, n);

    cout << "Sorted array: ";
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";

    return 0;
} 