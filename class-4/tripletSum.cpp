#include<bits/stdc++.h>
using namespace std;

// TC: O(n^2)
// AS: O(1)
bool tripletSum(vector<int> arr, int target) {

    int n = arr.size();
    sort(arr.begin(), arr.end());

    for (int i = 0; i < n - 2; i++) {
        int newTarget = target - arr[i];

        // 2-ptr approach to check if newTarget exists in arr[i + 1 ... n - 1]
        int left = i + 1, right = n - 1;
        while (left < right) {

            int curSum = arr[left] + arr[right];
            if (curSum == newTarget) {
                return true;
            }

            if (curSum > newTarget) {
                right--;
            } else {
                left++;
            }
        }
    }

    return false;
}

int main() {
    cout << tripletSum({1, 4, 45, 6, 10, 8}, 13) << endl;
    cout << tripletSum({1, 4, 45, 6, 10, 8}, 30) << endl;
    
    cout << tripletSum({1, 4, 45}, 53) << endl;
    cout << tripletSum({1, 4, 45}, 50) << endl;
} 