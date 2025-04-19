#include<bits/stdc++.h>
using namespace std;

// TC: O(n)
// AS: O(n)
int countSubarraysWithEqual0sAnd1s(vector<int> arr) { // arr containing 0s and 1s

    int n = arr.size();
    unordered_map<int, int> sumFreq;
    int result = 0;

    int sum = 0;
    sumFreq[0] = 1;

    for (int i = 0; i < n; i++) {
        // sum += (arr[i] == 1 ? +1 : -1);
        if (arr[i] == 1) {
            sum++;
        } else { // considering 0s as -1s.
            sum--;
        }
        result += sumFreq[sum];
        sumFreq[sum]++;
    }

    return result;
}

int main() {
    cout << countSubarraysWithEqual0sAnd1s({1, 0, 0, 1, 0, 1, 1}) << endl;
    cout << countSubarraysWithEqual0sAnd1s({1, 1, 1, 1, 0}) << endl;

    cout << countSubarraysWithEqual0sAnd1s({1, 1, 1, 1, 1}) << endl;
    cout << countSubarraysWithEqual0sAnd1s({0, 0, 0}) << endl;
} 