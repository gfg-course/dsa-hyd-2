#include<bits/stdc++.h>
using namespace std;

// TC: O(n)
// AS: O(1)
int longestSubstrLengthWithDistinctChars(string s) {

    vector<bool> isPresent(26, false);

    int left = 0, right = 0;
    int result = 0;

    while (right < s.length()) {
        if (!isPresent[s[right] - 'a']) {
            isPresent[s[right] - 'a'] = true;
            result = max(result, right - left + 1);
        } else {
            while (left < right && s[left] != s[right]) {
                isPresent[s[left] - 'a'] = false;
                left++;
            }
            left++;
        }
        right++;
    }

    return result;
}

int main() {
    cout << longestSubstrLengthWithDistinctChars("geeksforgeeks") << endl;
    cout << longestSubstrLengthWithDistinctChars("aaaa") << endl;
    cout << longestSubstrLengthWithDistinctChars("abcdefghij") << endl;
    cout << longestSubstrLengthWithDistinctChars("abcdeefghij") << endl;
} 