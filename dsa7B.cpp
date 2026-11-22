
#include <iostream>
using namespace std;

int road[20][20], visited[20], n;

void exploreRoad(int city) {
    cout << "Intersection " << city << " ";
    visited[city] = 1;

    for (int i = 0; i < n; i++) {
        if (road[city][i] == 1 && !visited[i])
            exploreRoad(i);
    }
}

int main() {
    int e, u, v, start;

    cout << "Enter number of intersections: ";
    cin >> n;

    cout << "Enter number of roads: ";
    cin >> e;

    cout << "Enter connected intersections:\n";
    for (int i = 0; i < e; i++) {
        cin >> u >> v;
        road[u][v] = 1;
        road[v][u] = 1;
    }

    cout << "Enter starting intersection: ";
    cin >> start;

    cout << "Road Network DFS:\n";
    exploreRoad(start);

    return 0;
}
