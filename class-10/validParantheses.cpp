#include<bits/stdc++.h>
using namespace std;

bool isSame(char op, char cl) {
    return 
        (op == '(' && cl == ')') ||
        (op == '{' && cl == '}') ||
        (op == '[' && cl == ']');
}

// TC: O(n)
// AS: O(n)
bool isValidExpression(string s) {

    stack<char> helper;
    for (int i = 0; i < s.length(); i++) {
        if (s[i] == '(' || s[i] == '{' || s[i] == '[') { // Opening bracket
            helper.push(s[i]);
        } else { // Closing bracket
            // Compare s[i] with helper.top()
            if (helper.empty()) {
                return false;
            }
            if (!isSame(helper.top(), s[i])) {
                return false;
            }
            helper.pop();
        }
    }

    // if (helper.empty()) {
    //     return true;
    // } else {
    //     return false;
    // }
    return helper.empty();
}

int main() {
    cout << isValidExpression("[()]") << endl;
    cout << isValidExpression("[(])") << endl;
    cout << isValidExpression("{[()]") << endl;
    cout << isValidExpression("[()]}") << endl;
    cout << isValidExpression("[[[[[[") << endl;
    cout << isValidExpression("[[[[[[]]]]]]") << endl;
}