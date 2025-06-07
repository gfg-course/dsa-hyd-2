#include<bits/stdc++.h>
using namespace std;

// TC: O(V + E)
// AS: O(V)
vector<int> bfs(vector<vector<int>> adj) {
    int n = adj.size();

    vector<bool> vis(n, false);
    queue<int> q;
    vector<int> result;

    q.push(0);
    vis[0] = true;

    while (!q.empty()) {
        int sz = q.size();

        for (int i = 0; i < sz; i++) {
            int curr = q.front();
            q.pop();

            result.push_back(curr);

            for (int neighbor : adj[curr]) {
                if (!vis[neighbor]) {
                    vis[neighbor] = true;
                    q.push(neighbor);
                }
            }
        }
    }
    return result;
}

int main() {
    
    vector<int> result = bfs({{3, 2},
                             {3, 6},
                             {0, 4},
                             {0, 1, 4},
                             {3, 2, 5},
                             {4},
                             {1}});

    for (int i : result) {
        cout << i << " ";
    }
}