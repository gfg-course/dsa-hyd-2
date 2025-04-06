#include<bits/stdc++.h>
using namespace std;

// TC: O(n)
// AS: O(1)
int maxSumInSubarray(vector<int> arr) {
    int n = arr.size();

    int maxTillIndex = arr[0], overallMax = arr[0];
    for (int i = 1; i < n; i++) {
        // if (maxTillIndex < 0) {
        //     maxTillIndex = arr[i];
        // } else {
        //     maxTillIndex += arr[i];
        // }
        maxTillIndex = max(arr[i], maxTillIndex + arr[i]);

        overallMax = max(overallMax, maxTillIndex);
    }

    return overallMax;
}

int main() {
    cout << maxSumInSubarray({-10, 2, 3, -2, 5}) << endl;
    cout << maxSumInSubarray({2, 8, 4, -10, 3}) << endl;
}