#include<bits/stdc++.h>
using namespace std;

// TC: O(n)
// AS: O(n)
vector<string> generateBinaryNumbers(int n) {
    queue<string> q;
    vector<string> result;

    q.push("1");
    int pushesIntoQueue = 1;

    while (pushesIntoQueue < n) {
        string curr = q.front();
        q.pop();

        result.push_back(curr);

        q.push(curr + "0");
        q.push(curr + "1");
        pushesIntoQueue += 2;
    }

    while (result.size() != n) {
        string curr = q.front();
        q.pop();

        result.push_back(curr);
    }

    return result;
}

// TC: O(n)
// AS: O(1)
vector<string> generateBinaryNumbersWithoutExtraSpace(int n) {
    
    vector<string> result;
    result.push_back("1");

    int front = 0;
    while (result.size() < n) {
        string curr = result[front];
        front++;

        result.push_back(curr + "0");
        result.push_back(curr + "1");
    }

    if (result.size() == n + 1) {
        result.pop_back();
    }

    return result;
}

int main() {
    vector<string> result = generateBinaryNumbersWithoutExtraSpace(11);
    for (string i : result) {
        cout << i << endl;
    }
}