#include<bits/stdc++.h>
using namespace std;

int getMinCoinsUtil(int i, int value, vector<int> coins, vector<vector<int>> &memo) {
    if (value == 0) {
        return 0;
    }
    if (i == coins.size()) {
        return 1e9;
    }

    if (memo[i][value] != -1) {
        return memo[i][value];
    }

    // Skip the current coin.
    int result = getMinCoinsUtil(i + 1, value, coins, memo);

    // Consider the current coin if possible.
    if (coins[i] <= value) {
        result = min(result, 1 + getMinCoinsUtil(i, value - coins[i], coins, memo));
    }

    return memo[i][value] = result;
}

// TC: O(2 ^ (max(n, value))) -> O(n * value)
// AS: O(max(n, value)) -> O(n * value)
int getMinCoins(vector<int> coins, int value) {
    int n = coins.size();

    vector<vector<int>> memo(n, vector<int> (value + 1, -1));

    int result = getMinCoinsUtil(0, value, coins, memo);
    if (result >= 1e9) {
        return -1;
    }
    return result;
}

int main() {

    cout << getMinCoins({2, 5, 3, 6}, 10) << endl;
    cout << getMinCoins({3, 3, 6}, 5) << endl;
}