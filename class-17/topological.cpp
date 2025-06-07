#include<bits/stdc++.h>
using namespace std;

void topologicalSortUtil(int u, vector<vector<int>> &adj, vector<bool> &vis,
                            stack<int> &s) {

    vis[u] = true;

    for (int v : adj[u]) {
        if (!vis[v]) {
            topologicalSortUtil(v, adj, vis, s);
        }
    }

    s.push(u);
}

vector<int> topologicalSort(vector<vector<int>> adj) {

    int n = adj.size();

    vector<int> result;
    stack<int> s;
    vector<bool> vis(n, false);

    for (int i = 0; i < n; i++) {
        if (!vis[i]) {
            topologicalSortUtil(i, adj, vis, s);
        }
    }

    while (!s.empty()) {
        result.push_back(s.top());
        s.pop();
    }

    return result;
}

// TC: O(V + E)
// AS: O(V)
vector<int> topologicalSortUsingInDegree(vector<vector<int>> adj) {

    int n = adj.size();
    vector<int> inDegree(n, 0);
    vector<int> result;

    for (int u = 0; u < n; u++) {
        for (int v : adj[u]) {
            inDegree[v]++;
        }
    }

    queue<int> q;
    for (int i = 0; i < n; i++) {
        if (inDegree[i] == 0) {
            q.push(i);
        }
    }

    while (!q.empty()) {
        int u = q.front();
        q.pop();

        result.push_back(u);

        for (int v : adj[u]) {
            inDegree[v]--;
            if (inDegree[v] == 0) {
                q.push(v);
            }
        }
    }

    return result;
}

int main() {
    
    vector<int> res = topologicalSort({{2},
                                       {0, 5},
                                       {},
                                       {5, 4},
                                       {},
                                       {4},
                                       {4},
                                       {1}});
    
    for (int i : res) {
        cout << i << " ";
    }
    cout << endl;

    res = topologicalSortUsingInDegree({{2},
                                       {0, 5},
                                       {},
                                       {5, 4},
                                       {},
                                       {4},
                                       {4},
                                       {1}});
    
    for (int i : res) {
        cout << i << " ";
    }
}