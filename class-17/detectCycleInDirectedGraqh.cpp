#include<bits/stdc++.h>
using namespace std;

bool isCyclicUtil(int curr, vector<vector<int>> &adj, 
                vector<bool> &vis, vector<bool> &recStack){ 
    
    vis[curr] = true;
    recStack[curr] = true;

    for (int neighbor : adj[curr]) {
        if (recStack[neighbor]) {
            return true;
        }
        if (!vis[neighbor] && isCyclicUtil(neighbor, adj, vis, recStack)) {
            return true;
        }
    }

    recStack[curr] = false;
    return false;
}

// TC: O(V + E)
// AS: O(V)
bool isCyclic(vector<vector<int>> adj) {
    int n = adj.size();
    vector<bool> vis(n, false);
    vector<bool> recStack(n, false);

    for (int i = 0; i < n; i++) {
        if (!vis[i]) {
            if (isCyclicUtil(i, adj, vis, recStack)) {
                return true;
            }
        }
    }

    return false;
}

int main() {
    cout << isCyclic({{1},
                      {5, 2}, 
                      {5, 3},
                      {4},
                      {1},
                      {}}) << endl;

    cout << isCyclic({{0, 1},
                      {}}) << endl;

    cout << isCyclic({{1, 2},
                      {2}, 
                      {}}) << endl;

    cout << isCyclic({{0, 1},
                      {1}}) << endl;
}