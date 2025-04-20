#include<bits/stdc++.h>
using namespace std;

// TC: O(2 ^ (max(n, target)))
// AS: max(n, target)
void getCombinationWithSumUtil(vector<int> &arr, int index, int target, vector<int> &curr, vector<vector<int>> &result) {
    if (target == 0) {
        result.push_back(curr);
        return;
    }
    if (target < 0 || index == arr.size()) {
        return;
    }


    // Possibility-1: skip the current element.
    getCombinationWithSumUtil(arr, index + 1, target, curr, result);

    // Possibility-2: consider the current element.
    curr.push_back(arr[index]);
    getCombinationWithSumUtil(arr, index, target - arr[index], curr, result);
    curr.pop_back();
}

vector<vector<int>> getCombinationWithSum(vector<int> arr, int target) {

    vector<vector<int>> result;
    vector<int> curr;

    getCombinationWithSumUtil(arr, 0, target, curr, result);
    return result;
}

int main() {
    vector<vector<int>> res = getCombinationWithSum({2, 7, 6, 5}, 16);
    for (auto i : res) {
        for (auto j : i) {
            cout << j << " ";
        }
        cout << endl;
    }
}
