#include<bits/stdc++.h>
using namespace std;

// TC: O(n)
// AS: O(n)
void printNTo1(int i, int n) {
    if (i == n + 1) {
        return;
    }

    printNTo1(i + 1, n);
    cout << i << endl;
}


// TC: O(n)
// AS: O(1)
void printNTo1TailRecursion(int n) {
    if (n == 0) {
        return;
    }

    cout << n << endl;
    printNTo1TailRecursion(n - 1);
}

// TC: O(n)
// AS: O(n)
int fact(int n) {
    if (n == 0) {
        return 1;
    }
    return n * fact(n - 1);
}

// TC: O(n)
// AS: O(1)
void factTailRecursive(int n, int &res) {
    if (n == 0) {
        return;
    }

    res = res * n;
    factTailRecursive(n - 1, res);
}

int main() {
    
    // printNTo1(1, 10);
    printNTo1TailRecursion(10);

    int res = 1;
    factTailRecursive(5, res);

    cout << res << endl;
} 