#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> dis;

void dfs(int node, int cur, int start, unordered_map<int, vector<int>> &adj, vector<bool> &vis)
{
    vis[node] = 1;
    dis[start][node] = cur;
    for (auto it : adj[node])
    {
        if (vis[it] == 0)
        {
            dfs(it, cur + 1, start, adj, vis);
        }
    }
}

int main()
{
    long n;
    cin >> n;
    unordered_map<int, vector<int>> adj;
    vector<long> val(n);
    dis.resize(n, vector<int>(n, 0));
    for (int i = 0; i < n; i++)
        cin >> val[i];
    for (int i = 0; i < n - 1; i++)
    {
        int u, v;
        cin >> u >> v;
        adj[u - 1].push_back(v - 1);
        adj[v - 1].push_back(u - 1);
    }

    for (int start = 0; start < n; start++)
    {
        vector<bool> vis(n, 0);
        dfs(start, 0, start, adj, vis);
    }

    long ans = 0;
    for (int i = 0; i < n; i++)
    {
        long cur = 0;
        for (int j = 0; j < n; j++)
        {
            cur += dis[i][j] * val[j];
        }
        ans = max(ans, cur);
    }
    cout << ans << endl;
}