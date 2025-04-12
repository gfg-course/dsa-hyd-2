#include<bits/stdc++.h>
using namespace std;

// TC: O(n + maxx)
// AS: O(maxx)
int maxInNRanges(vector<int> L, vector<int> R) {
    int n = R.size();
    int maxx = R[0];   

    for (int i = 1; i < n; i++) {
        maxx = max(maxx, R[i]);
    }

    vector<int> freq(maxx + 2, 0);

    for (int i = 0; i < n; i++) {
        freq[L[i]]++;
        freq[R[i] + 1]--;
    }

    // Prefix sum on the freq[] array.
    for (int i = 1; i < freq.size(); i++) {
        freq[i] += freq[i - 1];
    }

    int maxFreqIndex = 0;
    for (int i = 1; i < freq.size(); i++) {
        if (freq[i] > freq[maxFreqIndex]) {
            maxFreqIndex = i;
        }
    }

    return maxFreqIndex;
}

int main() {
    
    cout << maxInNRanges({1, 4, 3, 1}, {15, 8, 5, 4}) << endl;
} 