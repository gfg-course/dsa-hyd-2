#include<bits/stdc++.h>
using namespace std;

// TC: O(n)
// AS: O(1)
bool pairSum(vector<int> arr, int target) {

    int n = arr.size();
    if (n < 2) {
        return false;
    }

    int left = 0, right = n - 1;
    while (left < right) {

        int curSum = arr[left] + arr[right];
        if (curSum == target) {
            return true;
        }

        if (curSum > target) {
            right--;
        } else {
            left++;
        }
    }

    return false;    
}

int main() {
    
    cout << pairSum({1, 2, 5, 6, 10}, 8) << endl;
    cout << pairSum({1, 2, 5, 6, 10}, 9) << endl;

    cout << pairSum({1, 2, 3, 5, 6, 10}, 8) << endl;

    cout << pairSum({1, 2, 3}, 6) << endl;
    cout << pairSum({1, 2, 3, 3}, 6) << endl;
} 