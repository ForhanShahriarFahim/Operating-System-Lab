#include <bits/stdc++.h>

using namespace std;

map<string, set<string>> graph;
map<string, bool> vis;
string source;
bool deadlock = false;

void dfs(string node)
{
    vis[node] = true;
    for (string n : graph[node])
    {
        if (vis[n])
        {
            if (n == source) //... Cycle exists
            {
                deadlock = true;
            }
        }
        else
            dfs(n);
    }
}

int main()
{
    set<string> nodes; //... Contains all the process & resources
    string from, to;
    while (cin >> from >> to)
    {
        graph[from].insert(to); //... The edge direction is "from" -> "to"
        nodes.insert(from);
        nodes.insert(to);
    }
    for (string node : nodes) //... Checking every node as source for cycle detection
    {
        for (string n : nodes)
        {
            vis[n] = false;
        }
        source = node;
        dfs(node);
        if (deadlock)
        {
            cout << "Deadlock";
            return 0;
        }
    }
    cout << "No Deadlock";
}

/*//... Input Output:

...............Input:
T1 R1
R1 T2
T2 R3
R3 T5
T2 R4
R4 T3
T3 R5
T2 R5
R5 T4
T4 R2
R2 T1

..............Output:
Deadlock

...............Input:
T1 R1
T2 R3
R3 T5
T2 R4
R4 T3
T3 R5
T2 R5
R5 T4
T4 R2
R2 T1

..............Output:
No Deadlock

*/
