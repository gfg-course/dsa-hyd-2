#include<bits/stdc++.h>
using namespace std;


// TC: O(log(b))
// AS: O(log(b))
int power(int a, int b) {
    if (b == 0 || a == 1) {
        return 1;
    }

    int temp = power(a, b/2);

    if (b % 2 == 1) {
        return temp * temp * a;
    } else {
        return temp * temp;
    }
}


int main() {
    
}