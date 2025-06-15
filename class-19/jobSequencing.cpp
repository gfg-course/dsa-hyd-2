#include<bits/stdc++.h>
using namespace std;

class Job {
    public:

    int id;
    int deadline;
    int profit;

    Job(int id, int deadline, int profit) {
        this->id = id;
        this->deadline = deadline;
        this->profit = profit;
    }
};

bool profitsComp(Job* &a, Job* &b) {

    if (a->profit == b->profit) {
        return a->deadline > b->deadline;
    }

    return a->profit > b->profit;
}

// TC: O(nlog(n) + n*min(n, maxDeadline))
// AS: O(maxDeadline)
pair<int, int> jobSequencing(vector<Job*> jobs) {

    sort(jobs.begin(), jobs.end(), profitsComp);

    int n = jobs.size();
    int maxDeadline = 0;
    for (int i = 0; i < n; i++) {
        maxDeadline = max(maxDeadline, jobs[i]->deadline);
    }

    vector<int> slots(maxDeadline, -1);

    int jobsDone = 0, maxProfit = 0;
    for (int i = 0; i < n; i++) {

        int j = jobs[i]->deadline - 1;
        while (j >= 0) {
            if (slots[j] == -1) {
                slots[j] = jobs[i]->id;
                jobsDone++;
                maxProfit += jobs[i]->profit;
                break;
            }
            j--;
        }
    }

    return {jobsDone, maxProfit};
}

// TODO: Implement deadlineComp
pair<int, int> jobSequencingUsingPQ(vector<Job*> jobs) {
    // sort(jobs.begin(), jobs.end(), deadlineComp);

    int n = jobs.size();
    int jobsDone = 0, maxProfit = 0;

    priority_queue<int, vector<int>, greater<int>> profits;

    for (int i = 0; i < n; i++) {
        if (jobs[i]->deadline > jobsDone) {
            jobsDone++;
            maxProfit += jobs[i]->profit;

            profits.push(jobs[i]->profit);
        } else {
            if (jobs[i]->profit > profits.top()) {
                maxProfit += jobs[i]->profit - profits.top();
                profits.pop();
                profits.push(jobs[i]->profit);
            }
        }
    }

    return {jobsDone, maxProfit};
}

int main() {

    pair<int, int> res = jobSequencing({new Job(1, 2, 100), new Job(2, 1,19),
     new Job(3, 2, 27), new Job(4, 1, 25), new Job(5, 1, 15)});
    
    cout << res.first << " " << res.second << endl;
}