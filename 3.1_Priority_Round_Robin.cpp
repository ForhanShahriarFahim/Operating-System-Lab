
#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define pii pair<int, int>
#define pll pair<ll, ll>
#define vii vector<int>
#define SORT(v) sort(v.begin(), v.end())
#define RSORT(v) sort(v.rbegin(), v.rend())
#define ff first
#define ss second
#define nl "\n"
using namespace std;

int num, quantam;
double total_time = 0, turn_around = 0, waiting = 0;
vii bt(100), tat(100), pt(100);
vii times, process_no;
vector<pair<int, pair<int, int>>> process;

void print_table();
void gant_chart();
void FCFS();
void Average();
void RoundRobin(queue<pii> &process_RR);

int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    // taking inputs
    cin >> num >> quantam;
    int prior, brst;

    for (int i = 1; i <= num; i++)
    {
        cin >> brst >> prior;
        process.pb({prior, {i, brst}});
        bt[i] = brst;
        pt[i] = prior;
    }
    SORT(process);

    cout << "PRIORITY WITH ROUND ROBIN SCHEDULING ALGORITHM IMPLEMENTATION:" << nl << nl;
    FCFS();
    print_table();
    Average();
    gant_chart();

    return 0;
}

void FCFS()
{
    times.pb(0);
    int pri, prc, brs;
    for (int i = 0; i < process.size(); i++)
    {
        pri = process[i].ff;
        prc = process[i].ss.ff;
        brs = process[i].ss.ss;
        // Round Robin Check
        if (i + 1 < process.size() && process[i + 1].ff == pri)
        {
            queue<pii> process_RR;
            int pr, br;
            while (i < process.size())
            {
                pr = process[i].ss.ff;
                br = process[i].ss.ss;
                process_RR.push({pr, br});
                if (i + 1 < process.size() && process[i + 1].ff != pri)
                    break;
                i++;
            }
            RoundRobin(process_RR);
        }
        else
        {
            total_time += brs;
            tat[prc] = total_time;
            times.pb(total_time);
            process_no.pb(prc);
        }
    }
}

void RoundRobin(queue<pii> &process_RR)
{
    pii temp;
    int p_num, b_time;
    while (!process_RR.empty())
    {
        temp = process_RR.front();
        process_RR.pop();
        p_num = temp.ff;
        b_time = temp.ss;

        if (b_time <= quantam || process_RR.empty())
            total_time += b_time;
        else
        {
            total_time += quantam;
            b_time -= quantam;
            process_RR.push({p_num, b_time});
        }
        tat[p_num] = total_time;
        times.pb(total_time);
        process_no.pb(p_num);
    }
}

void print_table()
{
    cout << "---------------Table--------------" << nl;
    cout << "Process\tPriority\tBurst\tTurnAround\tWaiting" << nl;
    for (int i = 1; i <= num; i++)
        cout << "P" << i << "\t\t" << pt[i] << "\t\t\t" << bt[i] << "\t\t" << tat[i] << "\t\t\t" << tat[i] - bt[i] << nl;
    cout << nl;
}

void Average()
{
    cout << "---------------Average values--------------" << nl;
    for (int i = 1; i <= num; i++)
    {
        turn_around += tat[i];
        waiting += tat[i] - bt[i];
    }
    cout << "Average Turn around time = " << turn_around / num << nl;
    cout << "Average Waiting time = " << waiting / num << nl;
    cout << nl;
}

void gant_chart()
{
    cout << "---------------GANT CHART--------------" << nl;

    string sequence, dash;

    // Generating Process string
    sequence.pb('|');
    for (int i = 1; i < times.size(); i++)
    {
        for (int j = 0; j < times[i] - times[i - 1]; j++)
            sequence.pb(' ');
        sequence.pb('P');
        sequence.pb(process_no[i - 1] + '0');
        for (int j = 0; j < times[i] - times[i - 1]; j++)
            sequence.pb(' ');
        sequence.pb('|');
    }

    // Generating line for upper and lower
    for (int i = 0; i < sequence.size(); i++)
        dash.pb('-');
    // Printing the GANT Chart
    cout << dash << nl << sequence << nl << dash << nl;

    // Printing Completion time
    int i = 0;
    for (int j = 0; j < sequence.size(); j++)
    {
        if (sequence[j] == '|')
        {
            cout << times[i];
            if (times[i] > 9)
                j++;
            i++;
        }
        else
            cout << " ";
    }
    cout << nl;
}

/*
Sample Input:
5 3
5 3
1 1
10 2
8 2
4 2

Sample Output:
PRIORITY WITH ROUND ROBIN SCHEDULING ALGORITHM IMPLEMENTATION:

---------------Table--------------
Process	Priority	Burst	TurnAround	Waiting
P1		3			5		28			23
P2		1			1		1			0
P3		2			10		23			13
P4		2			8		22			14
P5		2			4		17			13

---------------Average values--------------
Average Turn around time = 18.2
Average Waiting time = 12.6

---------------GANT CHART--------------
------------------------------------------------------------------------------------------
| P2 |   P3   |   P4   |   P5   |   P3   |   P4   | P5 |   P3   |  P4  | P3 |     P1     |
------------------------------------------------------------------------------------------
0    1        4        7        10       13       16   17       20     22   23           28

*/