#include<bits/stdc++.h>
using namespace std;

// TODO-1: Search if the array is rotated anti-clockwise.
// TODO-2: Alt-approach: search for the smallest element (pivot) & do 2 binary searches.


// TC: O(log(n))
// AS: O(1)
int searchInSortedRotatedArray(vector<int> arr, int target) {

    int low = 0, high = arr.size() - 1;

    while (low <= high) {
        int mid = (low + high) / 2;

        if (arr[mid] == target) {
            return mid;
        }
        if (arr[low] <= arr[mid]) { // left half is sorted.
            if (target >= arr[low] && target < arr[mid]) {
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        } else { // right half is sorted.
            if (target > arr[mid] && target <= arr[high]) {
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }
    }

    return -1;
}


int main() {
    
} 