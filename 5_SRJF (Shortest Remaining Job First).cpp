#include <bits/stdc++.h>

using namespace std;

struct process
{
    string id;
    int burst, backup, arrival;
    int waiting = 0, completion = 0, turnaround = 0;
};

bool compareProcess(process x, process y)
{
    if (x.burst != y.burst)
        return x.burst < y.burst;
    else
        return x.arrival < y.arrival;
}

int main()
{
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);

    int size;
    cin >> size;
    vector<process> x(size);

    // Input format: Process-Id Arrival-Time Burst-Time
    for (int i = 0; i < size; i++)
    {
        cin >> x[i].id >> x[i].arrival >> x[i].burst;
        x[i].backup = x[i].burst;
    }

    // Main calculation
    int time = 0;
    vector<pair<string, int>> timeline;
    double aveTurnaround = 0, aveWaiting = 0;
    while (true)
    {
        sort(x.begin(), x.end(), compareProcess);
        bool flag = false;
        for (int i = 0; i < size; i++)
        {
            if (x[i].arrival <= time && x[i].burst)
            {
                x[i].burst--;
                time++;
                if (!x[i].burst)
                {
                    x[i].completion = time;
                    x[i].turnaround = x[i].completion - x[i].arrival;
                    aveTurnaround += x[i].turnaround;
                    x[i].waiting = x[i].turnaround - x[i].backup;
                    aveWaiting += x[i].waiting;
                }
                if (timeline.size() && timeline.back().first == x[i].id)
                {
                    timeline.back().second = time;
                }
                else
                {
                    timeline.push_back({x[i].id, time});
                }                    
                flag = true;
                break;
            }
        }
        if (!flag)
            break;
    }
    // Gantt Chart output
    string op = "|", border = "-";
    for (auto v : timeline)
    {
        op += "  " + v.first + "  |";
        border += "-------";
    }
    cout << border << "\n"
         << op << "\n"
         << border << "\n0";

    // Time output
    int in = 0;
    for (int i = 1; op[i]; i++)
    {
        if (op[i] == '|')
        {
            cout << timeline[in].second;
            if (timeline[in++].second > 9)
                i++;
        }
        else if (op[i + 1] == '|' and i + 2 == op.size())
            ;
        else
            cout << " ";
    }

    cout<<"\n\nAverage Turnaround Time: "<<aveTurnaround/size<<endl;
    cout<<"Average Waiting Time: "<<aveWaiting/size;

    // Average Waiting time, Turnaround time & Completion time output
    cout << "\n\nProcess | Waiting Time | Completion Time | Turnaround Time\n";
    cout << "----------------------------------------------------------\n";
    for (int i = 0; i < size; i++)
    {
        cout << x[i].id << "        " << x[i].waiting << "             ";
        if (x[i].waiting < 10)
            cout << " ";
        cout << x[i].completion << "                 ";
        if (x[i].completion < 10)
            cout << " ";
        cout << x[i].turnaround << "\n";
    }
    return 0;
}

/*input
4
P1 0 8
P2 1 4
P3 2 9
P4 3 5

Average Turnaround Time: 13
Average Waiting Time: 6.5

// Slide's output
// ------------------------------------
// |  P1  |  P2  |  P4  |  P1  |  P3  |
// ------------------------------------
// 0      1      5      10     17    26
*/