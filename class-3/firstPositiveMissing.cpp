#include<bits/stdc++.h>
using namespace std;

// TC: O(n)
// AS: O(1)
int firstPositiveMissing(vector<int> arr) {

    int n = arr.size();

    // Step-1
    for (int i = 0; i < n; i++) {
        if (arr[i] <= 0) {
            arr[i] = n + 1;
        }
    }

    // Step-2
    for (int i = 0; i < n; i++) {
        if (abs(arr[i]) >= 1 and abs(arr[i]) <= n) {
            int bucketIndex = abs(arr[i]) - 1;
            if (arr[bucketIndex] > 0) {
                arr[bucketIndex] *= -1;
            }
        }
    }

    // Step-3
    for (int i = 0; i < n; i++) {
        if (arr[i] > 0) {
            return i + 1;
        }
    }

    return n + 1;
}

int main() {
    cout << firstPositiveMissing({1, 2, 3, 4, 5}) << endl;
    cout << firstPositiveMissing({0, -10, 1, 3, -20}) << endl;
    cout << firstPositiveMissing({0, -10, 1, 2, 2, -20}) << endl;
}