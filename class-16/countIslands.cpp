#include<bits/stdc++.h>
using namespace std;

int dx[8] = {-1, -1, -1, +0, +0, +1, +1, +1};
int dy[8] = {-1, +0, +1, -1, +1, -1, +0, +1};

bool isSafe(int i, int j, vector<vector<int>> &arr) {
    return
        i >= 0 and i < arr.size() and
        j >= 0 and j < arr[i].size() and
        arr[i][j] == 1;
}

void dfs(int i, int j, vector<vector<int>> &arr) {
    arr[i][j] = 0;

    for (int k = 0; k < 8; k++) {
        int x = i + dx[k];
        int y = j + dy[k];

        if (isSafe(x, y, arr)) {
            dfs(x, y, arr);
        }
    }
}

// TC: O(n * m)
int countIslands(vector<vector<int>> arr) {
    int n = arr.size();
    int m = arr[0].size();

    int result = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (arr[i][j] == 1) {
                result++;
                dfs(i, j, arr);
            }
        }
    }

    return result;
}

int main() {
    
}