#include<bits/stdc++.h>
using namespace std;

int dx[4] =  {+1, +0, +0, -1};
int dy[4] =  {+0, -1, +1, +0};
char dm[4] = {'D', 'L', 'R', 'U'};

bool isSafe(int i, int j, vector<vector<int>> &maze) {
    return 
        i >= 0 && i < maze.size() && 
        j >= 0 && j < maze[i].size() && 
        maze[i][j] == 1;
}

// TC: O(4 ^ (n*n))
// AS: O(n*n)
void getPossiblePathsUtil(int i, int j, vector<vector<int>> &maze, string &curr, vector<string> &result) {
    if (i == maze.size() - 1 && j == maze[i].size() - 1) {
        result.push_back(curr);
        return;
    }

    maze[i][j] = 0;

    for (int k = 0; k < 4; k++) {
        int new_i = i + dx[k];
        int new_j = j + dy[k];
        char dir = dm[k];

        if (isSafe(new_i, new_j, maze)) {
            curr.push_back(dir);
            getPossiblePathsUtil(new_i, new_j, maze, curr, result);
            curr.pop_back();
        }
    }

    // // Down (i + 1, j)
    // if (i + 1 < maze.size() && maze[i + 1][j] == 1) {
    //     curr.push_back('D');
    //     getPossiblePathsUtil(i + 1, j, maze, curr, result);
    //     curr.pop_back();
    // }

    // // Left (i, j - 1)
    // if (j - 1 >= 0 && maze[i][j - 1] == 1) {
    //     curr.push_back('L');
    //     getPossiblePathsUtil(i, j - 1, maze, curr, result);
    //     curr.pop_back();
    // }

    // // Right (i, j + 1)
    // if (j + 1 < maze[i].size() && maze[i][j + 1] == 1) {
    //     curr.push_back('R');
    //     getPossiblePathsUtil(i, j + 1, maze, curr, result);
    //     curr.pop_back();
    // }

    // // Up (i - 1, j)
    // if (i - 1 >= 0 && maze[i - 1][j] == 1) {
    //     curr.push_back('U');
    //     getPossiblePathsUtil(i - 1, j, maze, curr, result);
    //     curr.pop_back();
    // }

    maze[i][j] = 1;
}

vector<string> getPossiblePaths(vector<vector<int>> maze) {

    string curr = "";
    vector<string> result;
    if (maze[0][0] == 0) {
        return {};
    }
    getPossiblePathsUtil(0, 0, maze, curr, result);
    return result;
}

int main() {
    
    vector<string> result = getPossiblePaths({{1, 0, 0, 0}, {1, 1, 0, 1}, {1, 1, 0, 0}, {0, 1, 1, 1}});

    for (string i : result) {
        cout << i << endl;
    }

}
