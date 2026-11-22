
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int main() {
    int n, e, u, v, start;

    cout << "Enter number of vertices: ";
    cin >> n;

    vector<int> adj[20];

    cout << "Enter number of edges: ";
    cin >> e;

    cout << "Enter edges:\n";
    for (int i = 0; i < e; i++) {
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    cout << "Enter starting vertex: ";
    cin >> start;

    bool visited[20] = {false};
    queue<int> q;

    visited[start] = true;
    q.push(start);

    cout << "BFS Traversal: ";

    while (!q.empty()) {
        int x = q.front();
        q.pop();

        cout << x << " ";

        for (int i : adj[x]) {
            if (!visited[i]) {
                visited[i] = true;
                q.push(i);
            }
        }
    }

    return 0;
}
