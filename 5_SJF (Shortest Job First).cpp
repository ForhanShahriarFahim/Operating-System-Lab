#include <bits/stdc++.h>

using namespace std;

struct process
{
    string id;
    int burst, waiting, turnaround;
};

bool compareProcess(process x, process y)
{
    return x.burst < y.burst;
}

int main()
{
    int size;
    cin >> size;
    vector<process> x(size);

    for (int i = 0; i < size; i++)
    {
        cin >> x[i].id >> x[i].burst;
    }
    sort(x.begin(), x.end(), compareProcess);

    int time_now = 0;
    double avg_waiting = 0, avg_turnaround = 0;
    vector<pair<string, int>> timeline;

    for (int i = 0; i < size; i++)
    {
        time_now += x[i].burst;
        timeline.push_back({x[i].id, time_now});
        x[i].turnaround = time_now;
        x[i].waiting = x[i].turnaround - x[i].burst;
        avg_waiting += x[i].waiting;
        avg_turnaround += x[i].turnaround;
    }

    string gantt_chart = "|", border = "-";
    for (auto z : timeline)
    {
        gantt_chart += "  " + z.first + "  |";
        border += "-------";
    }
    cout << "Gantt Chart:\n"
         << border << "\n"
         << gantt_chart << "\n"
         << border << "\n"
         << "0";

    int index = 0;
    for (int i = 1; gantt_chart[i]; i++)
    {
        if (gantt_chart[i] == '|')
        {
            cout << timeline[index].second;
            if (timeline[index++].second >= 10)
            {
                i++;
            }
        }
        else
            cout << " ";
    }

    cout << "\n\n"
         << "Average waiting time = " << avg_waiting / size << "\n"
         << "Average turnaround time = " << avg_turnaround / size << "\n\n"
         << "Process   |   Waiting Time   |   Turnaround Time\n"
         << "------------------------------------------------\n";
    for (int i = 0; i < size; i++)
    {
        cout << x[i].id << "              "
             << x[i].waiting << "                   "
             << x[i].turnaround << "\n";
    }
}

/*//... Sample Input-Output:
___________________________________________________________________________________________________________________________________________________________________________________________________________________________
Input:
4
P1 6
P2 8
P3 7
P4 3

___________________________________________________________________________________________________________________________________________________________________________________________________________________________
Output:
Gantt Chart:
------------------------------------
|  P5  |  P4  |  P1  |  P3  |  P2  |
------------------------------------
0      2      5      11     18     26

Average waiting time = 7.2
Average turnaround time = 12.4

Process   |   Waiting Time   |   Turnaround Time
------------------------------------------------
P5              0                   2
P4              2                   5
P1              5                   11
P3              11                  18
P2              18                  26

*/
