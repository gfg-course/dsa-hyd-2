#include<bits/stdc++.h>
using namespace std;

// TC: O(3 ^ (max(n, m))) -> O(n*m)
// AS: max(n, m) -> O(n*m)
int editDistanceUtil(int i, int j, string &s1, string &s2, vector<vector<int>> &memo) {
    if (i == s1.length()) {
        return s2.length() - j;
    }
    if (j == s2.length()) {
        return s1.length() - i;
    }
    if (memo[i][j] != -1) {
        return memo[i][j];
    }

    if (s1[i] == s2[j]) {
        memo[i][j] = editDistanceUtil(i + 1, j + 1, s1, s2, memo);
        return memo[i][j];
    }

    int insert = 1 + editDistanceUtil(i, j + 1, s1, s2, memo);
    int del = 1 + editDistanceUtil(i + 1, j, s1, s2, memo);
    int replace = 1 + editDistanceUtil(i + 1, j + 1, s1, s2, memo);

    memo[i][j] = min({insert, del, replace});
    return memo[i][j];
}

int editDistance(string s1, string s2) {
    int n = s1.length();
    int m = s2.length();

    vector<vector<int>> memo(n, vector<int> (m, -1));
    return editDistanceUtil(0, 0, s1, s2, memo);
}

int main() {
    cout << editDistance("anshuman", "antihuman") << endl;
    cout << editDistance("abcd", "dcba") << endl;
}