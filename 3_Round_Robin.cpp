#include <bits/stdc++.h>
using namespace std;
int main() {
  int no_of_process, quantum, x;
  cin >> no_of_process >> quantum;
  queue<pair<int, int>> Burst;
  vector<int> BurstTime(no_of_process + 1);
  for (int i = 1; i <= no_of_process; i++) {
    cin >> x;
    BurstTime[i] = x;
    Burst.push({i, x});
  }
  int time = 0;
  vector<int> Time_Break, Task;
  map<int, int> TurnOver;
  while (!Burst.empty()) {
    pair<int, int> a;
    a = Burst.front();
    Burst.pop();
    if (a.second <= quantum) {
      time += a.second;
      TurnOver[a.first] = time;
      Time_Break.push_back(time);
      Task.push_back(a.first);

    } else {
      time += quantum;
      a.second -= quantum;
      Time_Break.push_back(time);
      Task.push_back(a.first);
      Burst.push(a);
    }
  }
  cout << "TASK :  ";
  int avgT = 0, avgW = 0;
  for (int i = 1; i <= no_of_process; i++) {
    cout << i << " ";
  }
  cout << endl << "TURN :  ";
  for (int i = 1; i <= no_of_process; i++) {
    cout << TurnOver[i] << " ";
    avgT += TurnOver[i];
  }
  cout << endl << "Wait :  ";
  for (int i = 1; i <= no_of_process; i++) {
    cout << TurnOver[i] - BurstTime[i] << " ";
    avgW += TurnOver[i] - BurstTime[i];
  }
  cout << endl;
  cout << "AVERAGE TURNOVER : " << (double)avgT / no_of_process << endl;
  cout << "AVG WAITING : " << (double)avgW / no_of_process << endl;
  cout << "THE GANTTCHART: " << endl << 0;
  for (int i = 0; i < Time_Break.size(); i++) {
    cout << "---P" << Task[i] << "---" << Time_Break[i];
  }
}

/*
Input: 
3 2
7 5 6 
*/