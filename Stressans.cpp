#include <iostream>
#include <algorithm>
using namespace std;

struct Job {
    string id;
    int deadline;
    int profit;
};

bool compare(Job a, Job b) {
    return a.profit > b.profit;
}

int main() {

    Job jobs[] = {
        {"J1", 2, 100},
        {"J2", 1, 19},
        {"J3", 2, 27},
        {"J4", 1, 25},
        {"J5", 3, 15}
    };

    int n = 5;

    sort(jobs, jobs + n, compare);

    int maxDeadline = 0;

    for (int i = 0; i < n; i++) {
        if (jobs[i].deadline > maxDeadline) {
            maxDeadline = jobs[i].deadline;
        }
    }

    string schedule[maxDeadline + 1];
    bool slot[maxDeadline + 1] = {false};

    int totalProfit = 0;

    for (int i = 0; i < n; i++) {

        for (int j = jobs[i].deadline; j >= 1; j--) {

            if (!slot[j]) {
                schedule[j] = jobs[i].id;
                slot[j] = true;
                totalProfit += jobs[i].profit;
                break;
            }
        }
    }

    cout << "Job Sequencing with Deadlines" << endl;
    cout << endl;

    cout << "Jobs sorted by decreasing profit:" << endl;

    for (int i = 0; i < n; i++) {
        cout << jobs[i].id
             << "  Deadline: " << jobs[i].deadline
             << "  Profit: " << jobs[i].profit << endl;
    }

    cout << endl;

    cout << "Final Schedule:" << endl;

    for (int i = 1; i <= maxDeadline; i++) {
        cout << "Time Slot " << i << ": ";

        if (slot[i]) {
            cout << schedule[i];
        } else {
            cout << "Empty";
        }

        cout << endl;
    }

    cout << endl;

    cout << "Selected Jobs: ";

    for (int i = 1; i <= maxDeadline; i++) {
        if (slot[i]) {
            cout << schedule[i] << " ";
        }
    }

    cout << endl;

    cout << "Maximum Total Profit = " << totalProfit << endl;

    return 0;
}