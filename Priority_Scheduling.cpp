// Priority Scheduling Algorithm

#include "bits/stdc++.h"
using namespace std;
#define ll long long
#define pb push_back

int main()
{
    //freopen("PrioritySchedulingInput.txt", "r", stdin);
    ll n, i, j, k, l, burst, priority;
    string proc;
    cin >> n;

    vector<ll> waitingTime(n), turnaroundTime(n), burstTime(n), BT(n), TAT(n), Priority(n);
    vector<string> process;
    vector<pair<ll, ll>> priorityTime;

    for (i = 0; i < n; i++)
    {
        cin >> proc >> burst >> priority;
        process.pb(proc);
        burstTime[i] = burst;
        priorityTime.pb({priority, i});
        Priority[i] = priority;
    }
    sort(priorityTime.begin(), priorityTime.end());

    // Turnaround Time

    for (i = 0; i < n; i++)
    {
        if (i == 0)
            TAT[priorityTime[i].second] = burstTime[priorityTime[i].second];
        else
            TAT[priorityTime[i].second] = TAT[priorityTime[i - 1].second] + burstTime[priorityTime[i].second];
    }

    for (i = 0; i < n; i++)
        waitingTime[i] = TAT[i] - burstTime[i];

    // Printing Gantt Chart

    cout << "\nGantt Chart:\n";

    // Prinint top bar
    cout << " ";
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < burstTime[priorityTime[i].second]; j++)
            cout << "--";
        cout << " ";
    }

    // Printing process name
    cout << "\n|";

    for (i = 0; i < n; i++)
    {
        for (j = 0; j < burstTime[priorityTime[i].second] - 1; j++)
            cout << " ";
        cout << process[priorityTime[i].second];
        for (j = 0; j < burstTime[priorityTime[i].second] - 1; j++)
            cout << " ";
        cout << "|";
    }

    // Printing bottom bar
    cout << "\n ";
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < burstTime[priorityTime[i].second]; j++)
            cout << "--";
        cout << " ";
    }
    cout << "\n";

    // Printing turnaround time
    cout << "0";
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < burstTime[priorityTime[i].second]; j++)
            cout << "  ";
        if (TAT[priorityTime[i].second] > 9)
            cout << "\b"; // backspace : remove 1 space
        cout << TAT[priorityTime[i].second];
    }
    cout << "\n\n";

    cout << "Process\t\tBurst Time\tPriority\tWaiting Time\tTurnaround Time\n";
    for (i = 0; i < n; i++)
    {
        cout << process[i] << "\t\t"
             << burstTime[i] << "\t\t"
             << Priority[i] << "\t\t"
             << waitingTime[i] << "\t\t"
             << TAT[i] << "\n";
    }

    // Average Waiting Time
    ll sum = 0;
    for (i = 0; i < n; i++)
        sum += waitingTime[i];
    cout << "\nAverage Waiting Time: " << (double)sum / n;

    // Average Turnaround Time
    sum = 0;
    for (i = 0; i < n; i++)
        sum += TAT[i];
    cout << "\nAverage Turnaround Time: " << (double)sum / n;

    return 0;
}