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
        int u1, u2;
        cin >> u1 >> u2;
        adj[u1].push_back(u2);
        indegree[u2]++;
    }
    // Kahn's algorithm
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
        cout << v << " ";
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
}