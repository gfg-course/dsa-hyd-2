#include<bits/stdc++.h>
using namespace std;

vector<string> keypad = {"", 
                        "", "abc", "def", 
                        "ghi", "jkl", "mno", 
                        "pqrs", "tuv", "wxyz"};

// T(n) = 4 * T(n - 1) + c
// TC: O(4^n)
// AS: O(n)

// TODO: do a complete dry-run for some smaller input to understand how index, curr are changing.
void getWordsUsingKeypadUtil(vector<int> arr, int index, string &curr, vector<string> &result) {
    if (index == arr.size()) {
        result.push_back(curr);
        return;
    }

    int digit = arr[index];
    for (char ch : keypad[digit]) {
        curr.push_back(ch);
        getWordsUsingKeypadUtil(arr, index + 1, curr, result);
        curr.pop_back();
    }
}

vector<string> getWordsUsingKeypad(vector<int> arr) {
    
    vector<string> result;
    string curr = "";
    getWordsUsingKeypadUtil(arr, 0, curr, result);

    return result;
}

int main() {
    vector<string> res = getWordsUsingKeypad({2, 3});
    for (string i : res) {
        cout << i << " ";
    }
}
