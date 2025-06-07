#include<bits/stdc++.h>
using namespace std;

bool isSafe(int i, int j, int n) {
    return i >= 1 and i <= n and j >= 1 and j <= n;
}

// TC: O(n^2)
// AS: O(n^2)
int dx[8] = {-1, -2, -2, -1, +1, +2, +2, +1};
int dy[8] = {-2, -1, +1, +2, +2, +1, -1, -2};
int minStepsByKnight(vector<int> sourcePos, vector<int> targetPos, int n) {

    vector<vector<bool>> vis(n + 1, vector<bool> (n + 1, false));
    queue<pair<int, int>> q;

    q.push({sourcePos[0], sourcePos[1]});
    vis[sourcePos[0]][sourcePos[1]] = true;

    int levels = 0;

    while (!q.empty()) {
        int sz = q.size();

        for (int _ = 0; _ < sz; _++) {
            pair<int, int> curr = q.front();
            q.pop();

            int i = curr.first;
            int j = curr.second;

            if (i == targetPos[0] && j == targetPos[1]) {
                return levels;
            }

            for (int k = 0; k < 8; k++) {
                int newI = i + dx[k];
                int newJ = j + dy[k];

                if (isSafe(newI, newJ, n) && !vis[newI][newJ]) {
                    vis[newI][newJ] = true;
                    q.push({newI, newJ});
                }
            }
        }

        levels++;
    }

    // never executed.
    return -1;
}

int main() {
    cout << minStepsByKnight({3, 3}, {1, 2}, 3) << endl;
    cout << minStepsByKnight({4, 5}, {1, 1}, 6) << endl;
}