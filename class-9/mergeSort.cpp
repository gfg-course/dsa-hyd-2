#include<bits/stdc++.h>
using namespace std;

// TC: O(n)
// AS: O(n)
void merge(vector<int> &arr, int left, int mid, int right) {

    // 1st Half: arr[left ... mid]
    // 2nd Half: arr[mid+1 ... right]

    int i = left;
    int j = mid + 1;

    vector<int> temp;
    while (i <= mid && j <= right) {
        if (arr[i] < arr[j]) {
            temp.push_back(arr[i]);
            i++;
        } else {
            temp.push_back(arr[j]);
            j++;
        }
    }

    // 1st half is not exhaused and 2nd half exhausted
    while (i <= mid) {
        temp.push_back(arr[i]);
        i++;
    }

    // 2nd half is not exhaused and 1st half exhausted
    while (j <= right) {
        temp.push_back(arr[j]);
        j++;
    }

    for (int i = 0; i < temp.size(); i++) {
        arr[left + i] = temp[i]; 
    }
}

// TC: O(n * log(n))
// AS: 
void mergeSortUtil(vector<int> &arr, int left, int right) {
    if (left >= right) {
        return;
    }

    int mid = (left + right) / 2;
    
    // {left, mid}, {mid+1, right}
    mergeSortUtil(arr, left, mid);
    mergeSortUtil(arr, mid + 1, right);
    merge(arr, left, mid, right);
}

void mergeSort(vector<int> &arr) {
    mergeSortUtil(arr, 0, arr.size() - 1);
}

int main() {
    
    vector<int> arr = {4, 3, 10, 7, 9, 1, 11, 8};
    mergeSort(arr);

    for (int i : arr) {
        cout << i << " ";
    }

}