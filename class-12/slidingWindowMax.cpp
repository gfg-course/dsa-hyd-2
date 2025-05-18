#include<bits/stdc++.h>
using namespace std;

// TC: O(n)
// AS: O(k)
vector<int> slidingWindowMax(vector<int> arr, int k) {

    deque<int> dq;
    vector<int> result;

    int n = arr.size();
    if (k > n) {
        k = n;
    }

    for (int i = 0; i < k; i++) {
        while (!dq.empty() && arr[i] > arr[dq.back()]) {
            dq.pop_back();
        }
        dq.push_back(i);
    }
    
    result.push_back(arr[dq.front()]);

    // [i - k + 1, i] = (i) - (i + k - 1) + 1 = k
    for (int i = k; i < n; i++) {
        // If the front() of dq is out of the bound for the current
        // window, remove it from the potential answers.
        if (dq.front() < i - k + 1) {
            dq.pop_front();
        }

        while (!dq.empty() && arr[i] > arr[dq.back()]) {
            dq.pop_back();
        }
        dq.push_back(i);

        result.push_back(arr[dq.front()]);
    }

    return result;
}

int main() {
    
    vector<int> res1 = slidingWindowMax({1, 2, 3, 1, 4, 5, 2, 3, 6}, 3);
    vector<int> res2 = slidingWindowMax({8, 5, 10, 7, 9, 4, 15, 12, 90, 13}, 4);
    vector<int> res3 = slidingWindowMax({8, 7, 6, 5, 4, 3, 2, 1}, 3);

    for (int i : res1) {
        cout << i << " ";
    }
    cout << endl;
    for (int i : res2) {
        cout << i << " ";
    }
    cout << endl;
    for (int i : res3) {
        cout << i << " ";
    }
    cout << endl;
}