#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n, x;
    cin >> n;
    vector<pair<int, int>> Burst;
    vector<int> BT(n + 1);
    map<int, int> TurnOver;
    for (int i = 1; i <= n; i++)
    {
        cin >> x;
        BT[i] = x;
        Burst.push_back({x, i});
    }
    sort(Burst.begin(), Burst.end());
    int turn = 0;

    for (auto a : Burst)
    {

        turn += a.first;
        TurnOver[a.second] = turn;
    }
    
    cout << "TASK :  ";
    for (int i = 1; i <= n; i++)
    {
        cout << i << " ";
    }
    cout << endl<< "TURN :  ";
    int turnAround = 0, waitingTime = 0;
    for (int i = 1; i <= n; i++)
    {
        cout << TurnOver[i] << " ";
        turnAround+=TurnOver[i];
    }
    cout << endl  << "Wait :  ";
    for (int i = 1; i <= n; i++)
    {
        cout << TurnOver[i] - BT[i] << " ";
        waitingTime += TurnOver[i] - BT[i];
    }
    cout<<endl;
    cout << "AVG TURNOVER : " << double(turnAround) / n << endl;
    cout << "AVG WAITING : " << double(waitingTime) / n << endl;
    cout << endl<< "THE GANTTCHART: " << endl<< 0;

    for (auto a : Burst)
    {
        cout << "---P" << a.second << "---" << TurnOver[a.second];
    }
}