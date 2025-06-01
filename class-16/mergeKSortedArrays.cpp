#include<bits/stdc++.h>
using namespace std;

// TC: O(k^2 * log(k))
// AS: O(k)
vector<int> mergeKSortedArrays(vector<vector<int>> arr) {
    int n = arr.size();

    // <pair<int, pair<int, int>>
    priority_queue<pair<int, pair<int, int>>> pq; // {-value, {i, j}}

    for (int i = 0; i < n; i++) {
        pq.push({-arr[i][0], {i, 0}});
    }

    vector<int> res;

    while (!pq.empty()) {
        pair<int, pair<int, int>> curr = pq.top();
        pq.pop();

        int value = -curr.first;
        int i = curr.second.first;
        int j = curr.second.second;

        res.push_back(value);

        if (j + 1 < arr[i].size()) {
            pq.push({-arr[i][j + 1], {i, j + 1}});
        }
    }

    return res;
}


int main() {
    vector<int> res = mergeKSortedArrays({
                                            {3, 5, 6, 9},
                                            {1, 2, 3, 9},
                                            {7, 9, 11, 12},
                                            {1, 2, 3, 4}
                                        });

    for (int i  : res)     {
        cout << i << " ";
    }
}