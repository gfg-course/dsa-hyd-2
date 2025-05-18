#include<bits/stdc++.h>
using namespace std;

// TC: O(n)
// AS: O(n)
void reverseQueue(queue<int> &q) {
    if (q.empty()) {
        return;
    }

    int a = q.front();
    q.pop();
    reverseQueue(q);

    q.push(a);
}

int main() {
    queue<int> q;
    q.push(4);
    q.push(3);
    q.push(1);
    q.push(10);
    q.push(2);
    q.push(6);

    reverseQueue(q);

    while (!q.empty()) {
        cout << q.front() << " ";
        q.pop();
    }
}