#include<bits/stdc++.h>
using namespace std;

// TC: O(log(n))
int countDigits1ToN(int n) {

    int result = 0;
    
    // j = 10^(i - 1)
    for (int j = 1; j - 1 < n; j*=10) {
        result += (n - (j - 1));
    }

    return result;
}

int main() {
    cout << countDigits1ToN(10) << endl;
    cout << countDigits1ToN(25) << endl;
}