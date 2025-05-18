#include<bits/stdc++.h>
using namespace std;

int getCharToAppend(vector<int> &freq, vector<int> &firstOcc) {

    int charToAppend = -1;
    for (int i = 0; i < 26; i++) {
        if (freq[i] != 1) {
            continue;
        }

        if (charToAppend == -1 || firstOcc[i] < firstOcc[charToAppend]) {
            charToAppend = i;
        }
    }

    return charToAppend;
}

// TC: O(n)
// AS: O(1)
string firstNonRepeatingChars(string s) {
    vector<int> freq(26, 0);
    vector<int> firstOcc(26, -1);

    string result = "";
    for (int i = 0; i < s.length(); i++) {
        int charIdx = (s[i] - 'a');
        freq[charIdx]++;

        if (freq[charIdx] == 1) {
            firstOcc[charIdx] = i;
        }

        int charToAppend = getCharToAppend(freq, firstOcc);
        if (charToAppend == -1) {
            result.push_back('#');
        } else {
            result.push_back('a' + charToAppend);
        }
    }

    return result;
}

// -------------------------------------------------------

// TC: O(n)
// AS: O(1)
string firstNonRepeatingCharsUsingQueue(string s) {
    vector<int> freq(26, 0);
    queue<char> q;
    string result = "";

    for (int i = 0; i < s.length(); i++) {
        int charIdx = (s[i] - 'a');
        freq[charIdx]++;

        if (freq[charIdx] == 1) {
            q.push(s[i]);
        }

        while (!q.empty() && freq[q.front() - 'a'] > 1) {
            q.pop();
        }

        if (q.empty()) {
            result.push_back('#');
        } else {
            result.push_back(q.front());
        }
    }
    return result;
}

int main() {
    cout << firstNonRepeatingChars("aabc") << endl;
    cout << firstNonRepeatingChars("aacb") << endl;
    cout << firstNonRepeatingChars("aabbccd") << endl;
    cout << firstNonRepeatingChars("aabccdba") << endl;

    cout << firstNonRepeatingCharsUsingQueue("aabc") << endl;
    cout << firstNonRepeatingCharsUsingQueue("aacb") << endl;
    cout << firstNonRepeatingCharsUsingQueue("aabbccd") << endl;
    cout << firstNonRepeatingCharsUsingQueue("aabccdba") << endl;
}