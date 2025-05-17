#include<bits/stdc++.h>
using namespace std;

vector<int> nextSmallerElements(vector<int> arr) {
    int n = arr.size();
    vector<int> res(n);
    stack<int> s;

    for (int i = n - 1; i >= 0; i--) {
        while (!s.empty() && arr[i] <= arr[s.top()]) {
            s.pop();
        }
        if (s.empty()) {
            res[i] = n;
        } else {
            res[i] = s.top();
        }
        s.push(i);
    }

    return res;
}

vector<int> prevSmallerElements(vector<int> arr) {
    int n = arr.size();
    vector<int> res(n);
    stack<int> s;

    for (int i = 0; i < n; i++) {
        while (!s.empty() && arr[i] <= arr[s.top()]) {
            s.pop();
        }
        if (s.empty()) {
            res[i] = -1;
        } else {
            res[i] = s.top();
        }
        s.push(i);
    }

    return res;
}

// TC: O(n)
// AS: O(n)
int maxAreaInHistogram(vector<int> heights) {

    vector<int> prevSmaller = prevSmallerElements(heights);
    vector<int> nextSmaller = nextSmallerElements(heights);

    int maxArea = 0;
    for (int i = 0; i < heights.size(); i++) {
        int start = prevSmaller[i] + 1;
        int end = nextSmaller[i] - 1;

        int width = end - start + 1;
        int currentArea = width * heights[i];

        maxArea = max(maxArea, currentArea);
    }

    return maxArea;
}

int main() {
    
    cout << maxAreaInHistogram({6, 2, 5, 4, 5, 1, 6}) << endl;
    cout << maxAreaInHistogram({6, 6, 6, 6}) << endl;
    cout << maxAreaInHistogram({1, 2, 3, 4}) << endl;
    cout << maxAreaInHistogram({4, 3, 2, 1}) << endl;
}