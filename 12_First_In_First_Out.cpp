#include <bits/stdc++.h>

using namespace std;

void printState(vector<int> frames)
{
    for (int x : frames)
    {
        if (x != -1)
            cout << " " << x;
        else
            cout << " -";
    }
    cout << "\n";
}

int main()
{
    int size; //... Total number of frames
    cin >> size;
    vector<int> frames(size, -1);
    queue<int> arrival_order;
    int miss = 0;

    int page;
    while (cin >> page)
    {
        bool found = false;
        for (int x : frames)
        {
            if (x == page)
            {
                found = true;
                break;
            }
        }
        if (found)
        {
            cout << page << " ->\n";
            continue;
        }
        miss++;
        int out = -1;
        if (arrival_order.size() >= size)
        {
            out = arrival_order.front();
            arrival_order.pop();
        }
        arrival_order.push(page);
        for (int &x : frames)
        {
            if (x == out)
            {
                x = page;
                cout << page << " ->";
                printState(frames);
                break;
            }
        }
    }
    cout << "Total page fault = " << miss;
}

/*
...............Input:
3
7 0 1 2 0 3 0 4 2 3 0 3 2 1 2 0 1 7 0 1

..............Output:
7 -> 7 - -
0 -> 7 0 -
1 -> 7 0 1
2 -> 2 0 1
0 ->
3 -> 2 3 1
0 -> 2 3 0
4 -> 4 3 0
2 -> 4 2 0
3 -> 4 2 3
0 -> 0 2 3
3 ->
2 ->
1 -> 0 1 3
2 -> 0 1 2
0 ->
1 ->
7 -> 7 1 2
0 -> 7 0 2
1 -> 7 0 1
Total page fault = 15

*/
