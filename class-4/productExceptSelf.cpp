#include<bits/stdc++.h>
using namespace std;

// TC: O(n)
// AS: O(n)
vector<int> productExceptSelf(vector<int> arr) {
    int n = arr.size();

    vector<int> prefProd(n);
    vector<int> suffProd(n);

    prefProd[0] = arr[0];
    for (int i = 1; i < n - 1; i++) {
        prefProd[i] = prefProd[i - 1] * arr[i];
    }

    suffProd[n - 1] = arr[n - 1];
    for (int i = n - 2; i > 0; i--) {
        suffProd[i] = suffProd[i + 1] * arr[i];
    }

    vector<int> result(n);
    result[0] = suffProd[1];
    

    int pp = arr[0];
    for (int i = 1; i < n - 1; i++) {
        // result[i] = prefProd[i - 1] * suffProd[i + 1];
        result[i] = pp * suffProd[i + 1];
        pp *= arr[i];
    }
    // result[n - 1] = prefProd[n - 2];
    result[n - 1] = pp;

    return result;
}

int main() {
    vector<int> result = productExceptSelf({1, 2, 3, 4});
    vector<int> result2 = productExceptSelf({-1, 1, 0, -3, 3});
    vector<int> result3 = productExceptSelf({-1, 1, 0, 0, 3});

    for (int i : result) {
        cout << i << " ";
    }
    cout << endl;

    for (int i : result2) {
        cout << i << " ";
    }
    cout << endl;

    for (int i : result3) {
        cout << i << " ";
    }
    cout << endl;
} 