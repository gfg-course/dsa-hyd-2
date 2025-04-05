#include<bits/stdc++.h>
using namespace std;

bool isAlphaNumeric(char ch) {

    bool isLowercase = (ch >= 'a' && ch <= 'z');
    bool isUppercase = (ch >= 'A' && ch <= 'Z');
    bool isNumeric = (ch >= '0' && ch <= '9');

    return isLowercase || isUppercase || isNumeric;
}

bool isSame(char a, char b) {
    if (a == b) {
        return true;
    }

    return (a == (b - 'A' + 'a')) || ((a - 'A' + 'a') == b);
}

// TC: O(n)
// AS: O(1)
bool isSpecialPalindrome(string s) {

    int left = 0, right = s.length() - 1;

    while (left < right) {
        if (!isAlphaNumeric(s[left])) {
            left++;
        } else if (!isAlphaNumeric(s[right])) {
            right--;
        } else {
            if (!isSame(s[left], s[right])) {
                return false;
            }
            left++;
            right--;
        }
    }

    return true;
}


int main() {

    cout << isSpecialPalindrome("level") << endl;
    cout << isSpecialPalindrome("levels") << endl;
    cout << isSpecialPalindrome("race a car") << endl;
    cout << isSpecialPalindrome("A man: nama") << endl;
}