#include <bits/stdc++.h>
using namespace std;

int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    int v, e;
    cin >> v >> e;
    vector<vector<int>> adj(v + 1);
    vector<int> indegree(v + 1);
    for (int i = 0; i < e; i++)
    {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        indegree[v]++;
    }
    queue<int> q;
    for (int i = 1; i <= v; i++)
    {
        if (indegree[i] == 0)
        {
            q.push(i);
        }
    }
    while (!q.empty())
    {
        int v = q.front();
        q.pop();
        for (int child : adj[v])
        {
            indegree[child]--;
            if (indegree[child] == 0)
            {
                q.push(child);
            }
        }
    }
    bool cycle = false;
    for (int i = 1; i <= v; i++)
    {
        if (indegree[i] != 0)
        {
            cycle = true;
            break;
        }
    }
    if (cycle)
        cout << "There is a cycle\n";
    else
        cout << "There is no cycle\n";
}