#include<bits/stdc++.h>
using namespace std;

int maxScoreUtil(int i, int j, vector<int> coins) {

    if (i == j) {
        return coins[i];
    }
    if (i > j) {
        return 0;
    }

    int score1 = maxScoreUtil(i + 2, j, coins);
    int score2 = maxScoreUtil(i + 1, j - 1, coins);
    int score3 = maxScoreUtil(i + 1, j - 1, coins);
    int score4 = maxScoreUtil(i, j - 2, coins);

    // Pick coins[i]
    int pickI = coins[i] + min(score1, score2);

    // Pick coins[j]
    int pickJ = coins[j] + min(score3, score4);

    return max(pickI, pickJ);

}

int maxScore(vector<int> coins) {
    return maxScoreUtil(0, coins.size() - 1, coins);
}

int main() {
    cout << maxScore({5, 3, 70, 10}) << endl;
    cout << maxScore({5, 3, 5, 70, 10}) << endl;
}