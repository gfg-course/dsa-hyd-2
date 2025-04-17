#include<bits/stdc++.h>
using namespace std;

int getFirstOcc(vector<int> &arr, int target) {

    int low = 0, high = arr.size() - 1;

    int firstOcc = -1;

    while (low <= high) {
        int mid = (low + high) / 2;

        if (arr[mid] == target) {
            firstOcc = mid;
            high = mid - 1;
        }
        else if (arr[mid] > target) {
            high = mid - 1;
        } else {
            low = mid + 1;
        }
    }

    return firstOcc;
}

int getLastOcc(vector<int> &arr, int target) {

    int low = 0, high = arr.size() - 1;

    int lastOcc = -1;

    while (low <= high) {
        int mid = (low + high) / 2;

        if (arr[mid] == target) {
            lastOcc = mid;
            low = mid + 1;
        }
        else if (arr[mid] > target) {
            high = mid - 1;
        } else {
            low = mid + 1;
        }
    }

    return lastOcc;
}

// TC: O(log(n))
// AS: O(1)
vector<int> getFirstAndLastOcc(vector<int> arr, int x) {

    int firstOcc = getFirstOcc(arr, x);

    if (firstOcc == -1) {
        return {-1, -1};
    }

    int lastOcc = getLastOcc(arr, x);
    return {firstOcc, lastOcc};
}

int main() {
    
    vector<int> result1 = getFirstAndLastOcc({1, 3, 5, 5, 5, 5, 67, 123, 125}, 5);
    vector<int> result2 = getFirstAndLastOcc({1, 3, 5, 5, 5, 5, 67, 123, 125}, 123);
    vector<int> result3 = getFirstAndLastOcc({1, 3, 5, 5, 5, 5, 67, 123, 125}, 124);

    cout << result1[0] << " " << result1[1] << endl;
    cout << result2[0] << " " << result2[1] << endl;
    cout << result3[0] << " " << result3[1] << endl;
} 