
#include <iostream>
using namespace std;

int graph[20][20], visited[20], n;

void DFS(int v) {
    cout << v << " ";
    visited[v] = 1;

    for (int i = 0; i < n; i++) {
        if (graph[v][i] == 1 && !visited[i])
            DFS(i);
    }
}

int main() {
    int e, u, v, start;

    cout << "Enter vertices: ";
    cin >> n;

    cout << "Enter edges: ";
    cin >> e;

    cout << "Enter edges (u v):\n";
    for (int i = 0; i < e; i++) {
        cin >> u >> v;
        graph[u][v] = 1;
        graph[v][u] = 1;
    }

    cout << "Enter starting vertex: ";
    cin >> start;

    cout << "DFS Traversal: ";
    DFS(start);

    return 0;
}
