
#include <iostream>
#include <algorithm>
using namespace std;

struct Edge {
    int u, v, w;
};

int parent[20];

int find(int x) {
    if (parent[x] != x)
        parent[x] = find(parent[x]);
    return parent[x];
}

int main() {
    int n, e;

    cout << "Enter number of vertices: ";
    cin >> n;

    cout << "Enter number of edges: ";
    cin >> e;

    Edge edges[100];

    cout << "Enter edges (u v weight):\n";
    for (int i = 0; i < e; i++)
        cin >> edges[i].u >> edges[i].v >> edges[i].w;

    sort(edges, edges + e, [](Edge a, Edge b) {
        return a.w < b.w;
    });

    for (int i = 0; i < n; i++)
        parent[i] = i;

    int cost = 0, count = 0;

    cout << "Minimum Spanning Tree:\n";

    for (int i = 0; i < e && count < n - 1; i++) {
        int a = find(edges[i].u);
        int b = find(edges[i].v);

        if (a != b) {
            cout << edges[i].u << " - "
                 << edges[i].v << " : "
                 << edges[i].w << endl;

            parent[a] = b;
            cost += edges[i].w;
            count++;
        }
    }

    if (count == n - 1)
        cout << "Total MST Cost: " << cost;
    else
        cout << "Graph is disconnected";

    return 0;
}
