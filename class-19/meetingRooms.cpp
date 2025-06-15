#include<bits/stdc++.h>
using namespace std;

bool comp(pair<int, char> &a, pair<int, char> &b) {
    // if a & b have different times -> sort on time
    // if a & b have same time -> put 'e' event first

    if (a.first == b.first) {
        return a.second == 'e';
        // if (a.second == 'e') {
        //     return true;
        // } else {
        //     return false;
        // }
    }

    return a.first < b.first;
    // if (a.first < b.first) {
    //     return true;
    // } else {
    //     return false;
    // }
}

// TC: O(n * log(n))
// AS: O(n)
int getMinMeetingRooms(vector<vector<int>> meetings) {

    int n = meetings.size();
    vector<pair<int, char>> timeline;

    for (int i = 0; i < n; i++) {
        timeline.push_back({meetings[i][0], 's'});
        timeline.push_back({meetings[i][1], 'e'});
    }

    sort(timeline.begin(), timeline.end(), comp);

    int result = 0, current = 0;
    for (int i = 0; i < 2*n; i++) {
        if (timeline[i].second == 's') {
            current++;
        } else {
            current--;
        }
        result = max(result, current);
    }

    return result;
}


int main() {
    cout << getMinMeetingRooms({{0, 30},
                                {5, 10},
                                {15, 20}}) << endl;
    
    cout << getMinMeetingRooms({{1, 18},
                                {18, 23},
                                {15, 29},
                                {4, 15},
                                {2, 11},
                                {5, 13}}) << endl;

    cout << getMinMeetingRooms({{0, 30},
                                {30, 40}}) << endl;
}