#include<bits/stdc++.h>
using namespace std;

// TC: O(n + m)
// AS: O(1)
// SC: O(n * m)
bool searchInSortedMatrix(vector<vector<int>> arr, int x) {

    int n = arr.size();
    int m = arr[0].size();

    int i = 0, j = m - 1;

    while (i < n && j >= 0) {
        if (arr[i][j] == x) {
            return true;
        }
        if (x > arr[i][j]) {
            i++;
        } else {
            j--;
        }
    }

    return false;
}

int main() {
    cout << searchInSortedMatrix({{3, 30, 38},
                                  {36, 43, 60},
                                  {40, 51, 69}}, 36) << endl;
    cout << searchInSortedMatrix({{3, 30, 38},
                                  {36, 43, 60},
                                  {40, 51, 69}}, 62) << endl;
    cout << searchInSortedMatrix({{3, 30, 38},
                                  {36, 43, 60},
                                  {40, 51, 69}}, 40) << endl;
    cout << searchInSortedMatrix({{3, 30, 38},
                                  {36, 43, 60},
                                  {40, 51, 69}}, 41) << endl;
} 