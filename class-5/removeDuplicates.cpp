#include<bits/stdc++.h>
using namespace std;

// TC: O(n)
// AS: O(1)
int removeDuplicates(vector<int> &arr) {
    int n = arr.size();

    int i = 0; // duty is to keep track of unique elements.
    int j = 0; // duty is to bring the new elements.

    while (j < n) {

        arr[i] = arr[j];

        i++;
        j++;
        
        while (j < n && arr[j] == arr[j - 1]) {
            j++;
        }
    }

    return i;
}

int main() {
    vector<int> arr = {1, 1, 2, 2, 2, 3, 4, 4, 5};

    int size = removeDuplicates(arr);

    for (int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }
} 