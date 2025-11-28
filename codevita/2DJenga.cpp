
#include <bits/stdc++.h>
using namespace std;

struct Cell
{
    int row, col;
};

int R, C;
int board[55][55];
int keyID;

map<int, vector<Cell>> clusters;

bool inBounds(int rr, int cc)
{
    return rr >= 0 && rr < R && cc >= 0 && cc < C;
}

long long evaluateShift(int dRow, int dCol, bool flag)
{
    set<int> stErase;
    queue<int> q;

    if (clusters.find(keyID) == clusters.end())
        return LLONG_MAX;

    for (auto &tile : clusters[keyID])
    {
        int nr = tile.row + dRow;
        int nc = tile.col + dCol;

        if (inBounds(nr, nc))
        {
            int adjID = board[nr][nc];
            if (adjID != 0 && adjID != keyID)
            {
                if (!stErase.count(adjID))
                {
                    stErase.insert(adjID);
                    q.push(adjID);
                }
            }
        }
    }

    while (!q.empty())
    {
        int cur = q.front();
        q.pop();

        for (auto &tile : clusters[cur])
        {
            int nr = tile.row + dRow;
            int nc = tile.col + dCol;

            if (inBounds(nr, nc))
            {
                int adjID = board[nr][nc];
                if (adjID != 0 && adjID != cur && adjID != keyID)
                {
                    if (!stErase.count(adjID))
                    {
                        stErase.insert(adjID);
                        q.push(adjID);
                    }
                }
            }

            if (flag)
            {
                int upR = tile.row - 1;
                int upC = tile.col;

                if (inBounds(upR, upC))
                {
                    int upID = board[upR][upC];
                    if (upID != 0 && upID != cur && upID != keyID)
                    {
                        if (!stErase.count(upID))
                        {
                            stErase.insert(upID);
                            q.push(upID);
                        }
                    }
                }
            }
        }
    }

    long long cost = 0;
    for (int id : stErase)
        cost += id;
    return cost;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    if (!(cin >> R >> C))
        return 0;

    for (int i = 0; i < R; ++i)
    {
        for (int j = 0; j < C; ++j)
        {
            cin >> board[i][j];
            if (board[i][j] != 0)
            {
                clusters[board[i][j]].push_back({i, j});
            }
        }
    }

    cin >> keyID;

    long long bestCost = LLONG_MAX;
    string bestDir = "";

    struct Move
    {
        int dr, dc;
        string name;
        bool horiz;
    };
    vector<Move> moves = {
        {1, 0, "down", false},
        {-1, 0, "up", false},
        {0, -1, "left", true},
        {0, 1, "right", true}};

    for (auto &mv : moves)
    {
        long long cost = evaluateShift(mv.dr, mv.dc, mv.horiz);
        if (cost < bestCost)
        {
            bestCost = cost;
            bestDir = mv.name;
        }
    }

    cout << bestCost << " via " << bestDir << "\n";
    return 0;
}
