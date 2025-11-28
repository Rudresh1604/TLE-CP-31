#include <bits/stdc++.h>
using namespace std;

struct State
{
    int layer;
    int index;
    int steps;
};

int main()
{
    int layers;
    cin >> layers;

    vector<string> rings(layers);
    vector<int> len(layers);

    int totNodes = 0;

    for (int i = 0; i < layers; ++i)
    {
        cin >> rings[i];
        len[i] = rings[i].size();
        totNodes += len[i];
    }

    vector<vector<bool>> vis(layers);
    for (int i = 0; i < layers; ++i)
    {
        vis[i].assign(len[i], false);
    }

    queue<State> q;

    int outer = layers - 1;

    for (int i = 0; i < len[outer]; ++i)
    {
        if (rings[outer][i] == '0')
        {
            vis[outer][i] = true;
            q.push({outer, i, 1});
        }
    }

    int ans = -1;

    while (!q.empty())
    {
        State cur = q.front();
        q.pop();

        int layer = cur.layer;
        int idx = cur.index;
        int steps = cur.steps;

        if (layer == 0 && rings[0][idx] == '0')
        {
            ans = steps;
            break;
        }

        int L = len[layer];

        int left = (idx - 1 + L) % L;
        if (!vis[layer][left] && rings[layer][left] == '0')
        {
            vis[layer][left] = true;
            q.push({layer, left, steps + 1});
        }

        int right = (idx + 1) % L;
        if (!vis[layer][right] && rings[layer][right] == '0')
        {
            vis[layer][right] = true;
            q.push({layer, right, steps + 1});
        }

        if (layer > 0)
        {
            int innerPos = idx / 2;
            if (!vis[layer - 1][innerPos] && rings[layer - 1][innerPos] == '0')
            {
                vis[layer - 1][innerPos] = true;
                q.push({layer - 1, innerPos, steps + 1});
            }
        }

        if (layer < layers - 1)
        {
            int c0 = idx * 2;
            int c1 = c0 + 1;

            if (c0 < len[layer + 1] && !vis[layer + 1][c0] && rings[layer + 1][c0] == '0')
            {
                vis[layer + 1][c0] = true;
                q.push({layer + 1, c0, steps + 1});
            }
            if (c1 < len[layer + 1] && !vis[layer + 1][c1] && rings[layer + 1][c1] == '0')
            {
                vis[layer + 1][c1] = true;
                q.push({layer + 1, c1, steps + 1});
            }
        }
    }

    cout << ans;
    return 0;
}
