#include<bits/stdc++.h>
using namespace std;

bool isValid(int i, int j, vector<vector<int>> &arr) {
    return i >= 0 and i < arr.size() and 
            j >= 0 and j < arr[i].size() and
            arr[i][j] == 1;
}

// TC: O(n*m)
// AS: O(n*m)
int dx[4] = {+0, -1, +0, +1};
int dy[4] = {-1, +0, +1, +0};
int minTimeToRot(vector<vector<int>> arr) {

    queue<pair<int, int>> q;
    for (int i = 0; i < arr.size(); i++) {
        for (int j = 0; j < arr[i].size(); j++) {
            if (arr[i][j] == 2) {
                q.push({i, j});
            }
        }
    }

    int result = 0;
    while (!q.empty()) {
        int sz = q.size();

        for (int _ = 0; _ < sz; _++) {
            pair<int, int> curr = q.front();
            q.pop();

            int i = curr.first;
            int j = curr.second;

            for (int k = 0; k < 4; k++) {
                int newI = i + dx[k];
                int newJ = j + dy[k];

                if (isValid(newI, newJ, arr)) {
                    arr[newI][newJ] = 2;
                    q.push({newI, newJ});
                }
            }
        }

        result++;
    }

    for (int i = 0; i < arr.size(); i++) {
        for (int j = 0; j < arr[i].size(); j++) {
            if (arr[i][j] == 1) {
                return -1;
            }
        }
    }

    return result - 1;
}

int main() {
    
    cout << minTimeToRot({{0, 1, 2},
                          {0, 1, 2},
                          {2, 1, 1},
                          {0, 1, 1}}) << endl;

    cout << minTimeToRot({{2, 2, 0, 1}}) << endl;
    
    cout << minTimeToRot({{2, 2, 2, 2}}) << endl;
}