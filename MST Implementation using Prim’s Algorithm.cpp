#include <iostream>
#include <climits>
using namespace std;

#define V 5

int minKey(int key[], bool visited[]) {
    int min = INT_MAX;
    int minIndex = -1;

    for (int i = 0; i < V; i++) {
        if (!visited[i] && key[i] < min) {
            min = key[i];
            minIndex = i;
        }
    }

    return minIndex;
}

void prim(int graph[V][V]) {
    int parent[V];
    int key[V];
    bool visited[V];

    for (int i = 0; i < V; i++) {
        key[i] = INT_MAX;
        visited[i] = false;
    }

    key[0] = 0;
    parent[0] = -1;

    for (int count = 0; count < V - 1; count++) {
        int u = minKey(key, visited);

        visited[u] = true;

        for (int v = 0; v < V; v++) {
            if (graph[u][v] && !visited[v] &&
                graph[u][v] < key[v]) {

                parent[v] = u;
                key[v] = graph[u][v];
            }
        }
    }

    int totalCost = 0;

    cout << "Edges in Prim's MST:\n";

    for (int i = 1; i < V; i++) {
        cout << parent[i] << " - " << i
             << " : " << graph[i][parent[i]] << endl;

        totalCost += graph[i][parent[i]];
    }

    cout << "Minimum Cost = " << totalCost << endl;
}

int main() {
    int graph[V][V] = {
        {0, 2, 0, 6, 0},
        {2, 0, 3, 8, 5},
        {0, 3, 0, 0, 7},
        {6, 8, 0, 0, 9},
        {0, 5, 7, 9, 0}
    };

    prim(graph);

    return 0;
}