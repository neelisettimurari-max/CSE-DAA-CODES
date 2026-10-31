
#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    int n, W;
    int wt[100], val[100];
    int dp[101][1001] = {0};

    cout << "Enter number of items: ";
    cin >> n;

    cout << "Enter knapsack capacity: ";
    cin >> W;

    cout << "Enter weights of items: ";
    for (int i = 0; i < n; i++)
        cin >> wt[i];

    cout << "Enter values of items: ";
    for (int i = 0; i < n; i++)
        cin >> val[i];

    for (int i = 1; i <= n; i++) {
        for (int w = 0; w <= W; w++) {
            if (wt[i - 1] <= w) {
                int include = val[i - 1] +
                    dp[i - 1][w - wt[i - 1]];
                int exclude = dp[i - 1][w];

                dp[i][w] = max(include, exclude);
            } else {
                dp[i][w] = dp[i - 1][w];
            }
        }
    }

    cout << "Maximum value = " << dp[n][W] << endl;

    return 0;
}
