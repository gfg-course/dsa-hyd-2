#include<bits/stdc++.h>
using namespace std;

// TC: O(n*log(log(n)))
// AS: O(n)
vector<int> getAllPrimes(int n) {

    vector<bool> primes(n + 1, true);
    primes[0] = primes[1] = false;

    for (int i = 2; i*i <= n; i++) {
        if (primes[i]) {
            for (int j = i*i; j <= n; j += i) {
                primes[j] = false;
            }
        }
    }

    vector<int> result;
    for (int i = 2; i <= n; i++) {
        if (primes[i]) {
            result.push_back(i);
        }
    }

    return result;
}

int main() {
    
    vector<int> result = getAllPrimes(10);
    for (int i : result) {
        cout << i << " ";
    }
}