#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

// Comparison function to sort jobs by profit (descending order)
bool compareProfit(vector<int> &a, vector<int> &b) {
    return a[2] > b[2]; // compare profits
}

// Function to perform Job Sequencing
void jobSequencing(vector<vector<int>> &job, int n) {
    // Step 1: Sort jobs by profit
    sort(job.begin(), job.end(), compareProfit);

    // Step 2: Find the maximum deadline
    int maxDeadline = 0;
    for (int i = 0; i < n; i++) {
        if (job[i][1] > maxDeadline)
            maxDeadline = job[i][1];
    }

    // Step 3: Initialize slots
    vector<int> slot(maxDeadline + 1, -1);

    int count = 0, totalProfit = 0;

    // Step 4: Assign jobs greedily
    for (int i = 0; i < n; i++) {
        for (int j = job[i][1]; j > 0; j--) {
            if (slot[j] == -1) {
                slot[j] = job[i][0]; // assign job id
                count++;
                totalProfit += job[i][2];
                break;
            }
        }
    }

    // Step 5: Print results
    cout << "\nTotal Jobs Done: " << count;
    cout << "\nTotal Profit: " << totalProfit;
    cout << "\nJob Sequence: ";
    for (int i = 1; i <= maxDeadline; i++) {
        if (slot[i] != -1)
            cout << "J" << slot[i] << " ";
    }
    cout << endl;
}

int main() {
    int n;
    cout << "Enter number of jobs: ";
    cin >> n;

    vector<vector<int>> job(n, vector<int>(3));
    cout << "Enter job details (id deadline profit):\n";
    for (int i = 0; i < n; i++) {
        cin >> job[i][0] >> job[i][1] >> job[i][2];
    }

    jobSequencing(job, n);

    return 0;
}


/*
Enter number of jobs: 5
Enter job details (id deadline profit):
1 2 100
2 1 19
3 2 27
4 1 25
5 3 15
*/