#include<bits/stdc++.h>
using namespace std;

// TOOD: Painter's partition problem.

bool isPossible(vector<int> &books, int M, int mid) {

    int numStudents = 1, pages = 0;

    // Finding the minimum number of students required
    // such that no student received more than `mid` number of books.
    for (int i = 0; i < books.size(); i++) {
        if (pages + books[i] <= mid) {
            pages += books[i];
        } else {
            numStudents++;
            pages = books[i];
        }
    }

    return numStudents <= M;
}

// TC: O(n * log(sum))
// AS: O(1)
int allocatePages(vector<int> books, int M) {
    int n = books.size();
    if (n < M) {
        return -1;
    }

    int low = 0, high = 0;
    for (int i = 0; i < n; i++) {
        low = max(low, books[i]);
        high += books[i];
    }

    int result = high;
    while (low <= high) {
        int mid = (low + high) / 2;

        if (isPossible(books, M, mid)) {
            result = mid;
            high = mid - 1;
        } else {
            low = mid + 1;
        }
    }

    return result;
}

int main() {
    
    cout << allocatePages({12, 34, 67, 90}, 2) << endl;
    cout << allocatePages({10, 20, 10, 30}, 2) << endl;
} 