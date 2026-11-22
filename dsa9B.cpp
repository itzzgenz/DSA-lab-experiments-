
#include <iostream>
#include <algorithm>
using namespace std;

struct Edge {
    int s1, s2, cost;
};

int parent[20];

int find(int x) {
    if (parent[x] == x)
        return x;
    return parent[x] = find(parent[x]);
}

int main() {
    int n, e;

    cout << "Enter number of substations: ";
    cin >> n;

    cout << "Enter number of connections: ";
    cin >> e;

    Edge edges[100];

    cout << "Enter connections (s1 s2 wiring cost):\n";
    for (int i = 0; i < e; i++)
        cin >> edges[i].s1 >> edges[i].s2 >> edges[i].cost;

    sort(edges, edges + e, [](Edge a, Edge b) {
        return a.cost < b.cost;
    });

    for (int i = 0; i < n; i++)
        parent[i] = i;

    int total = 0, count = 0;

    cout << "\nOptimal Power Connections:\n";

    for (int i = 0; i < e && count < n - 1; i++) {
        int a = find(edges[i].s1);
        int b = find(edges[i].s2);

        if (a != b) {
            cout << "Substation " << edges[i].s1
                 << " - Substation " << edges[i].s2
                 << " : " << edges[i].cost << endl;

            parent[a] = b;
            total += edges[i].cost;
            count++;
        }
    }

    if (count == n - 1)
        cout << "Minimum Wiring Cost: " << total;
    else
        cout << "Network is disconnected";

    return 0;
}
