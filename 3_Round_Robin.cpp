#include <bits/stdc++.h>

using namespace std;

struct process
{
  string id;
  int burst, waiting, turnaround;
};

int main()
{
  int size;
  cin >> size;
  vector<process> x(size);
  queue<process> waiting_list;

  for (int i = 0; i < size; i++)
  {
    cin >> x[i].id >> x[i].burst;
    waiting_list.push(x[i]);
  }

  int time_now = 0, quantum = 4;
  double avg_waiting = 0, avg_turnaround = 0;
  vector<pair<string, int>> timeline;

  while (!waiting_list.empty())
  {
    process now = waiting_list.front();
    waiting_list.pop();
    int quantum_now = min(now.burst, quantum);
    time_now += quantum_now;
    timeline.push_back({now.id, time_now});
    now.burst -= quantum_now;
    if (!now.burst)
    {
      for (auto &p : x)
      {
        if (p.id == now.id)
        {
          p.turnaround = time_now;
          p.waiting = time_now - p.burst;
          avg_waiting += p.waiting;
          avg_turnaround += p.turnaround;
          break;
        }
      }
    }
    else
      waiting_list.push(now);
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
3
P1 24
P2 3
P3 3
___________________________________________________________________________________________________________________________________________________________________________________________________________________________
Output:
Gantt Chart:
---------------------------------------------------------
|  P1  |  P2  |  P3  |  P1  |  P1  |  P1  |  P1  |  P1  |
---------------------------------------------------------
0      4      7      10     14     18     22     26     30

Average waiting time = 5.66667
Average turnaround time = 15.6667

Process   |   Waiting Time   |   Turnaround Time
------------------------------------------------
P1              6                   30
P2              4                   7
P3              7                   10

*/
//...