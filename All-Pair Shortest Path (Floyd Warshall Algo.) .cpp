#include <iostream>
#include <algorithm>
using namespace std;

#define INF 99999

int main() {
    int n;
    cout << "Enter number of vertices: ";
    cin >> n;

    int dist[10][10];

    cout << "Enter adjacency matrix (use 99999 for infinity):\n";
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> dist[i][j];
        }
    }

    // Floyd-Warshall Algorithm
    for (int k = 0; k < n; k++) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (dist[i][k] != INF && dist[k][j] != INF) {
                    dist[i][j] = min(dist[i][j],
                                     dist[i][k] + dist[k][j]);
                }
            }
        }
    }

    cout << "\nAll-Pairs Shortest Distance Matrix:\n";
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (dist[i][j] == INF)
                cout << "INF ";
            else
                cout << dist[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}