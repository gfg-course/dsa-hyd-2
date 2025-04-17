#include<bits/stdc++.h>
using namespace std;

// TC: O(log(n))
// AS: O(1)
bool binarySearch(vector<int> arr, int target) {

    int low = 0, high = arr.size() - 1;

    while (low <= high) {
        int mid = (low + high) / 2;

        if (arr[mid] == target) {
            return true;
        }
        if (arr[mid] > target) {
            high = mid - 1;
        } else {
            low = mid + 1;
        }
    }

    return false;
}

int main() {
    
    cout << binarySearch({5, 7, 10, 50, 60, 100}, 50) << endl;
    cout << binarySearch({5, 7, 10, 50, 60, 100}, 5) << endl;
    cout << binarySearch({5, 7, 10, 50, 60, 100}, 100) << endl;

    cout << binarySearch({5, 7, 10, 50, 60, 100}, 55) << endl;
} 