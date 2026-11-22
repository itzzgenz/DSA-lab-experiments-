
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int main() {
    int n, e, u, v, start;

    cout << "Enter number of users: ";
    cin >> n;

    vector<int> friends[20];

    cout << "Enter number of friendships: ";
    cin >> e;

    cout << "Enter friendship pairs:\n";
    for (int i = 0; i < e; i++) {
        cin >> u >> v;
        friends[u].push_back(v);
        friends[v].push_back(u);
    }

    cout << "Enter starting user: ";
    cin >> start;

    bool visited[20] = {false};
    queue<int> q;

    q.push(start);
    visited[start] = true;

    cout << "Connected Users (BFS): ";

    while (!q.empty()) {
        int user = q.front();
        q.pop();

        cout << user << " ";

        for (int x : friends[user]) {
            if (!visited[x]) {
                visited[x] = true;
                q.push(x);
            }
        }
    }

    return 0;
}
