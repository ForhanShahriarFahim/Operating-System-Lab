#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Process
{
    int pid;
    int brust_time;
    int brust_remain;
    int arrival_time;
    int priority_value;
    int waiting_time;
    int turnaround_time;
    int start_time;
    int complete_time;
    bool is_complete;
};

void print_table(vector<Process> &p, int n)
{
    cout << "TABLE:" << endl;
    puts("+-----+------------+--------------+----------+-----------------+--------------+---------------+");
    puts("| PID | Burst Time | Arrival Time | Priority | Turnaround Time | Waiting Time | Complete Time |");
    puts("+-----+------------+--------------+----------+-----------------+--------------+---------------+");

    for (int i = 0; i < n; i++)
    {
        printf("| %2d  |     %2d     |      %2d      |    %2d    |        %2d       |      %2d      |      %2d       |\n", p[i].pid, p[i].brust_time, p[i].arrival_time, p[i].priority_value, p[i].turnaround_time, p[i].waiting_time, p[i].complete_time);
        puts("+-----+------------+--------------+----------+-----------------+--------------+---------------+");
    }
}

int main()
{
    //freopen("input.txt", "r", stdin);

    int n;
    cin >> n;
    vector<Process> p(n);
    for (int i = 0; i < n; i++)
    {
        cin >> p[i].brust_time >> p[i].arrival_time >> p[i].priority_value;
        p[i].pid = i + 1;
        p[i].brust_remain = p[i].brust_time;
        p[i].is_complete = false;
    }

    // for (int i = 0; i < n; i++) {
    //     cout << p[i].pid << " " << p[i].brust_time << " " << p[i].arrival_time << " " << p[i].complete_time << " " << p[i].waiting_time << " " << p[i].turnaround_time << endl;
    // }

    vector<pair<int, int>> list(100);
    int time = 0, completed = 0, prv = -1, cnt = -1, single_time = 0;
    while (completed != n)
    {
        int idx = -1, min_priority_value = 1000;
        for (int i = 0; i < n; i++)
        {
            if (!p[i].is_complete and p[i].arrival_time <= time)
            {
                if (p[i].priority_value < min_priority_value)
                {
                    min_priority_value = p[i].priority_value;
                    idx = i;
                }
                if (p[i].priority_value == min_priority_value)
                {
                    if (p[i].arrival_time < p[idx].arrival_time)
                    {
                        idx = i;
                    }
                }
            }
        }
        if (idx != -1)
        {
            if (idx != prv)
            {
                cnt++;
                single_time = 1;
                list[cnt] = {idx, single_time};
                prv = idx;
            }
            else
            {
                single_time++;
                list[cnt] = {idx, single_time};
            }

            if (p[idx].brust_remain == p[idx].brust_time)
            {
                p[idx].start_time = time;
            }
            p[idx].brust_remain--;
            time++;
            if (p[idx].brust_remain == 0)
            {
                p[idx].complete_time = time;
                p[idx].turnaround_time = p[idx].complete_time - p[idx].arrival_time;
                p[idx].waiting_time = p[idx].turnaround_time - p[idx].brust_time;
                p[idx].is_complete = true;
                completed++;
            }
        }
        else
        {
            time++;
        }
    }

    puts("+-----+------------+");
    puts("| PID | Cycle Use  |");
    puts("+-----+------------+");
    for (int i = 0; i < cnt; i++)
    {
        printf("| %2d  |     %2d     |\n", list[i].first + 1, list[i].second);
        puts("+-----+------------+");
    }
    cout << endl;
    print_table(p, n);
    // for (int i = 0; i < n; i++) {
    //     cout << p[i].pid << " " << p[i].brust_time << " " << p[i].arrival_time << " " << p[i].complete_time << " " << p[i].waiting_time << " " << p[i].turnaround_time << endl;
    // }
}