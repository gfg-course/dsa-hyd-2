#include<bits/stdc++.h>
using namespace std;

// TC: O(n)
// AS: O(n)
bool checkZeroSumSubarray(vector<int> arr) {

    int n = arr.size();

    unordered_set<int> sums;
    int sum = 0;

    sums.insert(0);
    for (int i = 0; i < n; i++) {
        sum += arr[i];
        if (sums.find(sum) != sums.end()) { // If the sum has been seen before.
            return true;
        }
        sums.insert(sum);
    }

    return false;
}

int main() {
    cout << checkZeroSumSubarray({4, 2, -3, 1, 6}) << endl;
    cout << checkZeroSumSubarray({1, 2, -3, 10, 11}) << endl;
    cout << checkZeroSumSubarray({1, 2, 0, 10, 11}) << endl;
    cout << checkZeroSumSubarray({1, 2, 3, -1, -3, -2}) << endl;

    cout << checkZeroSumSubarray({1, 2, 3, 10, 11}) << endl;
    cout << checkZeroSumSubarray({-1, -2, -3, -10, -11}) << endl;
} 