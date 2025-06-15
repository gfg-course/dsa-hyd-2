#include<bits/stdc++.h>
using namespace std;

int getMaxValueUtil(int i, int W, vector<int> &vals, vector<int> &wts, vector<vector<int>> &memo) {
    if (i == vals.size() || W == 0) {
        return 0;
    }

    if (memo[i][W] != -1) {
        return memo[i][W];
    }

    // Skip
    int result = getMaxValueUtil(i + 1, W, vals, wts, memo);

    // Include
    if (wts[i] <= W) {
        result = max(result, vals[i] + getMaxValueUtil(i + 1, W - wts[i], vals, wts, memo));
    }

    memo[i][W] = result;
    return memo[i][W];
}

// TC: O(2^n) -> O(n*W)
// AS: O(n) -> O(n*W)
int getMaxValue(vector<int> vals, vector<int> wts, int W) {

    int n = vals.size();
    vector<vector<int>> memo(n, vector<int> (W + 1, -1));

    return getMaxValueUtil(0, W, vals, wts, memo);
}

// TC: O(n*W)
// AS: O(n*W)
int getMaxValueUsingBottomUp(vector<int> vals, vector<int> wts, int W) {
    int n = vals.size();
    vector<vector<int>> dp(n + 1, vector<int> (W + 1));

    for (int i = 0; i <= n; i++) {
        dp[i][0] = 0;
    }
    for (int j = 0; j <= W; j++) {
        dp[0][j] = 0;
    }

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= W; j++) {
            dp[i][j] = dp[i - 1][j];
            if (wts[i - 1] <= j) {
                dp[i][j] = max(dp[i][j], vals[i - 1] + dp[i - 1][j - wts[i - 1]]);
            }
        }
    }

    return dp[n][W];
}

int main() {

    cout << getMaxValue({60, 100, 120}, {10, 20, 50}, 50) << endl;
}