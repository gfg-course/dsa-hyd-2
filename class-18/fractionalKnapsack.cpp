#include<bits/stdc++.h>
using namespace std;

// TC: O(n * log(n))
// AS: O(n)
double getMaxValue(vector<int> vals, vector<int> wts, int W) {

    vector<pair<double, int>> valPerWtToWt;
    int n = vals.size();

    for (int i = 0; i < n; i++) {
        valPerWtToWt.push_back({(double)vals[i]/wts[i], wts[i]});
    }

    sort(valPerWtToWt.begin(), valPerWtToWt.end());

    double maxValue = 0;
    for (int i = n - 1; i >= 0; i--) {
        double valByWt = valPerWtToWt[i].first;
        int wt = valPerWtToWt[i].second;

        if (wt <= W) {
            maxValue += wt * valByWt;
            W -= wt;
        } else {
            maxValue += W * valByWt;
            W = 0;
            break;
        }
    }

    return maxValue;
}

int main() {

    cout << getMaxValue({60, 100, 120}, {10, 20, 30}, 50) << endl;
    cout << getMaxValue({10, 10, 100}, {10, 20, 30}, 50) << endl;
}