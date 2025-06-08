#include<bits/stdc++.h>
using namespace std;

vector<vector<pair<int, int>>> buildAdj(vector<vector<int>> &edges, int V) {

    vector<vector<pair<int, int>>> adj(V);

    for (vector<int> edge : edges) {
        int u = edge[0];
        int v = edge[1];
        int w = edge[2];

        adj[u].push_back({v, w});
        adj[v].push_back({u, w});
    }

    return adj;
}


vector<int> dijikstra(int V, vector<vector<int>> edges, int src) {

    vector<vector<pair<int, int>>> adj = buildAdj(edges, V);

    vector<int> dist(V, 1e9);
    dist[src] = 0;

    priority_queue<pair<int, int>, 
                   vector<pair<int, int>>, 
                   greater<pair<int, int>>> pq; // Min-Heap. {dist, node}

    pq.push({dist[src], src});

    while (!pq.empty()) {
        // V * log(V)
        auto curr = pq.top();
        pq.pop();

        int distU = curr.first;
        int u = curr.second;
        
        // E * log(V)
        for (pair<int, int> neighbor : adj[u]) {
            int v = neighbor.first;
            int distUV = neighbor.second;

            if (distU + distUV < dist[v]) {
                dist[v] = distU + distUV;
                pq.push({dist[v], v});
            }
        }
    }

    return dist;
}

int main() {

    vector<vector<int>> edges = {{0, 1, 4},
                                 {0, 7, 8},
                                 {1, 7, 11},
                                 {1, 2, 8},
                                 {2, 8, 2},
                                 {7, 8, 7},
                                 {7, 6, 1},
                                 {8, 6, 6},
                                 {6, 5, 2},
                                 {2, 5, 4},
                                 {2, 3, 7},
                                 {3, 5, 14},
                                 {3, 4, 9},
                                 {5, 4, 10}};
    
    vector<int> dist = dijikstra(9, edges, 0);

    for (int i = 0; i < dist.size(); i++) {
        cout << i << " : " << dist[i] << endl;
    }
}