#include <bits/stdc++.h>
using namespace std;

struct Hint
{
    int timeStep;
    int x1, y1, x2, y2;
};

int main()
{
    int rows, cols;
    cin >> rows >> cols;

    vector<string> arr(rows);
    for (int i = 0; i < rows; i++)
    {
        cin >> arr[i];
    }

    int k;
    cin >> k;

    vector<Hint> clues(k);
    for (int i = 0; i < k; i++)
    {
        cin >> clues[i].timeStep >> clues[i].x1 >> clues[i].y1 >> clues[i].x2 >> clues[i].y2;

        clues[i].x1--;
        clues[i].y1--;
        clues[i].x2--;
        clues[i].y2--;
    }

    string pattern;
    cin >> pattern;
    int len = pattern.size();

    vector<vector<int>> vis(rows, vector<int>(cols, 0));
    vector<vector<pair<int, int>>> allPaths;

    int dx[4] = {1, -1, 0, 0};
    int dy[4] = {0, 0, 1, -1};

    function<void(int, int, int, vector<pair<int, int>> &)> explore =
        [&](int r, int c, int idx, vector<pair<int, int>> &path)
    {
        if (arr[r][c] != pattern[idx])
            return;

        if (idx == len - 1)
        {
            allPaths.push_back(path);
            return;
        }

        vis[r][c] = 1;

        for (int d = 0; d < 4; d++)
        {
            int nr = r + dx[d];
            int nc = c + dy[d];

            if (nr >= 0 && nr < rows && nc >= 0 && nc < cols && !vis[nr][nc])
            {
                path.push_back({nr, nc});
                explore(nr, nc, idx + 1, path);
                path.pop_back();
            }
        }

        vis[r][c] = 0;
    };

        for (int r = 0; r < rows; r++)
    {
        for (int c = 0; c < cols; c++)
        {
            if (arr[r][c] == pattern[0])
            {
                vector<pair<int, int>> path;
                path.push_back({r, c});
                explore(r, c, 0, path);
            }
        }
    }

    if (allPaths.empty())
    {
        cout << "Impossible";
        return 0;
    }

    int incorrect = 0;

    for (auto &h : clues)
    {
        int t = h.timeStep;

        if (t < 1 || t > len)
        {
            incorrect++;
            continue;
        }

        bool valid = true;
        for (auto &p : allPaths)
        {
            auto [x, y] = p[t - 1];
            if (!(x >= h.x1 && x <= h.x2 && y >= h.y1 && y <= h.y2))
            {
                valid = false;
                break;
            }
        }

        if (valid)
            incorrect++;
    }

    if (incorrect == 0)
        cout << "All clues are correct";
    else
        cout << incorrect;

    return 0;
}
