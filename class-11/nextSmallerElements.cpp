#include<bits/stdc++.h>
using namespace std;

// TC: O(n)
// AS: O(n)
vector<int> nextSmallerElements(vector<int> arr) {
    int n = arr.size();
    vector<int> res(n);
    stack<int> s;

    for (int i = n - 1; i >= 0; i--) {
        while (!s.empty() && arr[i] <= s.top()) {
            s.pop();
        }
        if (s.empty()) {
            res[i] = -1;
        } else {
            res[i] = s.top();
        }
        s.push(arr[i]);
    }

    return res;
}


int main() {
    vector<int> res1 = nextSmallerElements({6, 8, 0, 4, 10});
    vector<int> res2 = nextSmallerElements({1, 2, 3, 4, 5});
    vector<int> res3 = nextSmallerElements({5, 4, 3, 2, 1});

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