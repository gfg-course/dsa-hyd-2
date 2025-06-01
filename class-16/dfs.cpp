#include<bits/stdc++.h>
using namespace std;

void dfsUtil(int curr, vector<vector<int>> &adj, 
            vector<bool> &vis, vector<int> &result) {

    vis[curr] = true;
    result.push_back(curr);

    // for (int v = 0; v < adj[curr].size(); v++) {
        // {curr->v} edge exists if adj[curr][v] == 1
    // }

    for (int neighbor : adj[curr]) {
        if (!vis[neighbor]) {
            dfsUtil(neighbor, adj, vis, result);
        }
    }
}

// TC: O(V + E)
// AS: O(V)
vector<int> dfs(vector<vector<int>> adj) {
    int V = adj.size();

    vector<int> result;
    vector<bool> vis(V, false);

    for (int i = 0; i < V; i++) {
        if (!vis[i]) {
            dfsUtil(i, adj, vis, result);
        }
    }
    return result;
}

int main() {

    vector<vector<int>> adj =  {{0, 1, 2},
                                {0, 3, 5},
                                {0, 6},
                                {1, 4},
                                {3, 5},
                                {1, 4},
                                {2},
                                {8},
                                {7}};

    int V = 9;
    for (int i = 0; i < 9; i++) {
        cout << i << " -> [";
        for (int j : adj[i]) {
            cout << j << ", ";
        }
        cout << "]\n";
    }

    vector<int> res = dfs(adj);
    for (int i  : res) {
        cout << i << " ";
    }
}