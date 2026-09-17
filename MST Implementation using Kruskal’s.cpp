#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Edge {
    int u, v, weight;
};

int findParent(int parent[], int i) {
    if (parent[i] == i)
        return i;
    return parent[i] = findParent(parent, parent[i]);
}

void unionSet(int parent[], int rank[], int u, int v) {
    u = findParent(parent, u);
    v = findParent(parent, v);

    if (rank[u] < rank[v])
        parent[u] = v;
    else if (rank[u] > rank[v])
        parent[v] = u;
    else {
        parent[v] = u;
        rank[u]++;
    }
}

void kruskal(vector<Edge> edges, int V) {
    sort(edges.begin(), edges.end(),
         [](Edge a, Edge b) {
             return a.weight < b.weight;
         });

    int parent[V], rank[V];

    for (int i = 0; i < V; i++) {
        parent[i] = i;
        rank[i] = 0;
    }

    int totalCost = 0;
    int count = 0;

    cout << "Edges in Kruskal's MST:\n";

    for (Edge e : edges) {
        int u = findParent(parent, e.u);
        int v = findParent(parent, e.v);

        if (u != v) {
            cout << e.u << " - " << e.v
                 << " : " << e.weight << endl;

            totalCost += e.weight;
            unionSet(parent, rank, u, v);
            count++;

            if (count == V - 1)
                break;
        }
    }

    cout << "Minimum Cost = " << totalCost << endl;
}

int main() {
    int V = 4;

    vector<Edge> edges = {
        {0, 1, 10},
        {0, 2, 6},
        {0, 3, 5},
        {1, 3, 15},
        {2, 3, 4}
    };

    kruskal(edges, V);

    return 0;
}