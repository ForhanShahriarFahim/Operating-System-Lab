#include <bits/stdc++.h>
using namespace std;
int main()
{
    int no_of_process, x;
    cin >> no_of_process;
    vector<pair<int, int>> Burst;
    vector<int> burst_time(no_of_process + 1);
    map<int, int> TurnOver;
    for (int i = 1; i <= no_of_process; i++)
    {
        cin >> x;
        burst_time[i] = x;
        Burst.push_back({x, i});
    }
    sort(Burst.begin(), Burst.end());
    int turnAroundT = 0;

    for (auto a : Burst)
    {

        turnAroundT += a.first;
        TurnOver[a.second] = turnAroundT;
    }
    
    cout << "TASK :  ";
    for (int i = 1; i <= no_of_process; i++)
    {
        cout << i << " ";
    }
    cout << endl<< "TURN :  ";
    int turnAround = 0, waitingTime = 0;
    for (int i = 1; i <= no_of_process; i++)
    {
        cout << TurnOver[i] << " ";
        turnAround+=TurnOver[i];
    }
    cout << endl  << "Wait :  ";
    for (int i = 1; i <= no_of_process; i++)
    {
        cout << TurnOver[i] - burst_time[i] << " ";
        waitingTime += TurnOver[i] - burst_time[i];
    }
    cout<<endl;
    cout << "AVG TURNOVER : " << double(turnAround) / no_of_process << endl;
    cout << "AVG WAITING : " << double(waitingTime) / no_of_process << endl;
    cout << endl<< "THE GANTTCHART: " << endl<< 0;

    for (auto a : Burst)
    {
        cout << "---P" << a.second << "---" << TurnOver[a.second];
    }
}

/*
Input:
3
13 3 7
*/
