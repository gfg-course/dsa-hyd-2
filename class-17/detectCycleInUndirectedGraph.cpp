#include<bits/stdc++.h>
using namespace std;

bool isCyclicUtil(int curr, int parent, vector<vector<int>> &adj, vector<bool> &vis) {
    vis[curr] = true;

    for (int neighbor : adj[curr]) {
        if (neighbor != parent && vis[neighbor]) {
            return true;
        }
        if (!vis[neighbor] && isCyclicUtil(neighbor, curr, adj, vis)) {
            return true;
        }
    }

    return false;
}

// TC: O(V + E)
// AS: O(V)
bool isCyclic(vector<vector<int>> adj) {
    int n = adj.size();

    vector<bool> vis(n, false);

    for (int i = 0; i < n; i++) {
        if (!vis[i]) {
            if (isCyclicUtil(i, -1, adj, vis)) {
                return true;
            }
        }
    }

    return false;
}

int main() {
    
}