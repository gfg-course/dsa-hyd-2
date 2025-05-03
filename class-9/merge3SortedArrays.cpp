#include<bits/stdc++.h>
using namespace std;

int inf = INT_MAX;

// TC: O(A + B + C)
// AS: O(1)
vector<int> merge3SortedArrays(vector<int> A, vector<int> B, vector<int> C) {

    vector<int> result;

    int i = 0, j = 0, k = 0;
    while (i < A.size() || j < B.size() || k < C.size()) {
        int a = i < A.size() ? A[i] : inf;
        int b = j < B.size() ? B[j] : inf;
        int c = k < C.size() ? C[k] : inf;

        int mn = min({a, b, c});
        result.push_back(mn);

        if (mn == a) {
            i++;
        } else if (mn == b) {
            j++;
        } else {
            k++;
        }
    }

    return result;
}

int main() {
    
    vector<int> result = merge3SortedArrays({1, 3, 10, 11}, {1, 2, 7}, {3, 5, 8});
    for (int i : result) {
        cout << i << " ";
    }
}