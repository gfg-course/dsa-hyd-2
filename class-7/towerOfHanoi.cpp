#include<bits/stdc++.h>
using namespace std;

// TC -> T(n) = 2*T(n - 1) + c -> O(2^n)
// AS: O(n)
int towerOfHanoiWithPathsPrinted(int n, string A, string B, string C) {
    if (n == 0) {
        return 0;
    }

    int result = towerOfHanoiWithPathsPrinted(n - 1, A, C, B);
    
    result++; // Move n-th rod from A to C.
    cout << "Move disk " << n << " from " << A << " to " << C << endl;

    result += towerOfHanoiWithPathsPrinted(n - 1, B, A, C);

    return result;
}

// TC -> T(n) = T(n - 1) + c -> O(n)
// AS: O(n)
int towerOfHanoi(int n) {
    if (n == 0) {
        return 0;
    }

    int result = towerOfHanoi(n - 1);

    return 2*result + 1;
}

int main() {
    cout << towerOfHanoiWithPathsPrinted(5, "A", "B", "C");
    // cout << towerOfHanoi(5) << endl;
} 