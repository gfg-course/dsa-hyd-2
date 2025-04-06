#include<bits/stdc++.h>
using namespace std;

// TC: O(nm)
// AS: O(1)
void booleanMatrix(vector<vector<bool>> &arr) {

    int n = arr.size();
    int m = arr[0].size();

    bool topRowContainsZero = false;
    bool leftColContainsZero = false;

    for (int i = 0; i < n; i++) {
        if (arr[i][0] == 0) {
            leftColContainsZero = true;
            break;
        }
    }
    for (int j = 0; j < m; j++) {
        if (arr[0][j] == 0) {
            topRowContainsZero = true;
            break;
        }
    }

    for (int i = 1; i < n; i++) {
        for (int j = 1; j < m; j++) {
            if (arr[i][j] == 0) {
                arr[i][0] = 0;
                arr[0][j] = 0;
            }
        }
    }

    for (int i = 1; i < n; i++) {
        for (int j = 1; j < m; j++) {
            if (arr[i][0] == 0 || arr[0][j] == 0) {
                arr[i][j] = 0;
            }
        }
    }

    if (topRowContainsZero) {
        for (int j = 0; j < m; j++) {
            arr[0][j] = 0;
        }
    }

    if (leftColContainsZero) {
        for (int i = 0; i < n; i++) {
            arr[i][0] = 0;
        }
    }
}

int main() {
    
    vector<vector<bool>> arr = {{1, 0, 1}, {1, 1, 1}, {1, 0, 1}};
    booleanMatrix(arr);

    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }
}