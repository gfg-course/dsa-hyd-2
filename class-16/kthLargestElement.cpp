#include<bits/stdc++.h>
using namespace std;

// TC: O(n*log(k))
// AS: O(k)
int kthLargestElement(vector<int> arr, int k) {

    // Min-Heap
    priority_queue<int, vector<int>, greater<int>> pq;

    for (int i = 0; i < k; i++) {
        pq.push(arr[i]);
    }

    for (int i = k; i < arr.size(); i++) {
        if (arr[i] > pq.top()) {
            pq.pop();
            pq.push(arr[i]);
        }
    }

    return pq.top();
}

int main() {

    cout << kthLargestElement({9, 5, 3, 4, 2}, 3) << endl;
    cout << kthLargestElement({1, 2, 4, 3, 4, 3}, 3) << endl;
    cout << kthLargestElement({9, 5, 3, 4, 2}, 1) << endl;
    cout << kthLargestElement({9, 5, 3, 4, 2}, 5) << endl;
}