#include<bits/stdc++.h>
using namespace std;

// TC: O(log(n))
// AS: O(1)
int getSqrt(int n) {

    int low = 1, high = n;

    int result = -1;
    while (low <= high) {
        int mid = (low + high) / 2;

        if (mid * mid == n) {
            return mid;
        }
        if (mid * mid > n) {
            high = mid - 1;
        } else {
            result = mid;
            low = mid + 1;
        }
    }

    return result;
}

int main() {
    
    cout << getSqrt(1) << endl;
    cout << getSqrt(10) << endl;
    cout << getSqrt(25) << endl;
} 