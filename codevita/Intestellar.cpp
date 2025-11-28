#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int MaxTime = 50;

vector<pair<ll, ll>> buildOrbit(int r)
{
    if (r == 0)
        return {{0, 0}};

    vector<pair<ll, ll>> path;

    // Start at (r, 0) - rightmost point
    ll x = r, y = 0;

    // Move UP along right edge (from y=0 to y=2r)
    for (int i = 0; i < 2 * r; i++)
    {
        path.push_back({x, y});
        y++;
    }

    // Move LEFT along top edge (from x=r to x=-r)
    for (int i = 0; i < 2 * r; i++)
    {
        path.push_back({x, y});
        x--;
    }

    // Move DOWN along left edge (from y=2r to y=0)
    for (int i = 0; i < 2 * r; i++)
    {
        path.push_back({x, y});
        y--;
    }

    // Move RIGHT along bottom edge (from x=-r to x=r)
    for (int i = 0; i < 2 * r; i++)
    {
        path.push_back({x, y});
        x++;
    }

    return path;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int relationCount;
    cin >> relationCount;

    unordered_map<string, string> parentMap;
    unordered_map<string, int> orbitRadius;
    set<string> allNodes;

    for (int i = 0; i < relationCount; i++)
    {
        string child, parent;
        int radius;
        cin >> child >> parent >> radius;

        parentMap[child] = parent;
        orbitRadius[child] = radius;
        allNodes.insert(child);
        allNodes.insert(parent);
    }

    string source, target;
    cin >> source >> target;

    allNodes.insert(source);
    allNodes.insert(target);

    // Find root nodes (nodes without parents)
    vector<string> rootNodes;
    for (auto &node : allNodes)
    {
        if (parentMap.find(node) == parentMap.end())
        {
            rootNodes.push_back(node);
        }
    }

    // Assign positions to root nodes - spread them out
    unordered_map<string, pair<ll, ll>> rootPositions;
    for (size_t i = 0; i < rootNodes.size(); i++)
    {
        rootPositions[rootNodes[i]] = {i * 10000LL, 0LL};
    }

    // Find maximum orbit radius for precomputation
    int maxRadius = 0;
    for (auto &entry : orbitRadius)
    {
        maxRadius = max(maxRadius, entry.second);
    }

    // Precompute orbit paths for all radii
    vector<vector<pair<ll, ll>>> orbitPaths(maxRadius + 1);
    for (int r = 0; r <= maxRadius; r++)
    {
        orbitPaths[r] = buildOrbit(r);
    }

    // Debug: print orbit paths
    // for (int r = 1; r <= maxRadius; r++) {
    //     cout << "Radius " << r << " orbit path:" << endl;
    //     auto path = orbitPaths[r];
    //     for (int i = 0; i < min(10, (int)path.size()); i++) {
    //         cout << "  " << i << ": (" << path[i].first << "," << path[i].second << ")" << endl;
    //     }
    //     cout << "  Perimeter: " << path.size() << endl;
    // }

    // Create node ID mapping
    unordered_map<string, int> nodeId;
    vector<string> idToName;
    int idCounter = 0;
    for (auto &node : allNodes)
    {
        nodeId[node] = idCounter++;
        idToName.push_back(node);
    }

    int n = allNodes.size();
    vector<int> parentId(n, -1);
    vector<int> radiusArr(n, 0);
    vector<vector<int>> children(n);

    // Build the tree structure
    for (auto &entry : parentMap)
    {
        string child = entry.first;
        string parent = entry.second;
        int cid = nodeId[child];
        int pid = nodeId[parent];
        parentId[cid] = pid;
        children[pid].push_back(cid);
        radiusArr[cid] = orbitRadius[child];
    }

    // Assign root coordinates
    vector<pair<ll, ll>> rootCoords(n, {0, 0});
    for (auto &entry : rootPositions)
    {
        string node = entry.first;
        pair<ll, ll> pos = entry.second;
        rootCoords[nodeId[node]] = pos;
    }

    // Compute positions for all nodes at all times
    vector<vector<pair<ll, ll>>> positions(n, vector<pair<ll, ll>>(MaxTime + 1, {0, 0}));

    for (int t = 0; t <= MaxTime; t++)
    {
        // Process nodes in BFS order to ensure parents are processed before children
        queue<int> q;
        vector<bool> visited(n, false);

        // Start with root nodes
        for (int i = 0; i < n; i++)
        {
            if (parentId[i] == -1)
            {
                q.push(i);
                visited[i] = true;
                positions[i][t] = rootCoords[i];
            }
        }

        while (!q.empty())
        {
            int node = q.front();
            q.pop();

            // Process children of current node
            for (int child : children[node])
            {
                if (!visited[child])
                {
                    visited[child] = true;
                    int radius = radiusArr[child];

                    if (radius == 0)
                    {
                        positions[child][t] = positions[node][t];
                    }
                    else
                    {
                        int perimeter = 8 * radius;
                        int orbitIndex = t % perimeter;
                        auto offset = orbitPaths[radius][orbitIndex];
                        positions[child][t] = {
                            positions[node][t].first + offset.first,
                            positions[node][t].second + offset.second};
                    }

                    q.push(child);
                }
            }
        }
    }

    // Debug: print positions for B and C
    int aId = nodeId["A"];
    int bId = nodeId["B"];
    int cId = nodeId["C"];

    // cout << "Positions over time:" << endl;
    // for (int t = 0; t <= 10; t++) {
    //     cout << "Time " << t << ":" << endl;
    //     cout << "  A: (" << positions[aId][t].first << "," << positions[aId][t].second << ")" << endl;
    //     cout << "  B: (" << positions[bId][t].first << "," << positions[bId][t].second << ")" << endl;
    //     cout << "  C: (" << positions[cId][t].first << "," << positions[cId][t].second << ")" << endl;
    //
    //     // Calculate distance between B and C
    //     ll dx = abs(positions[bId][t].first - positions[cId][t].first);
    //     ll dy = abs(positions[bId][t].second - positions[cId][t].second);
    //     cout << "  Distance B->C: " << (dx + dy) << endl;
    // }

    int srcId = nodeId[source];
    int dstId = nodeId[target];

    // Find earliest time when spaceship can reach destination
    int earliest = -1;
    for (int T = 0; T <= MaxTime; T++)
    {
        bool reachable = false;

        // Try all departure times from 0 to T
        for (int depart = 0; depart <= T; depart++)
        {
            auto startPos = positions[srcId][depart];
            auto endPos = positions[dstId][T];

            ll dx = abs(startPos.first - endPos.first);
            ll dy = abs(startPos.second - endPos.second);
            ll manhattan = dx + dy;

            // Check if we can travel the Manhattan distance in available time
            if (manhattan <= (T - depart))
            {
                reachable = true;
                break;
            }
        }

        if (reachable)
        {
            earliest = T;
            break;
        }
    }

    if (earliest >= 0)
    {
        cout << earliest << "\n";
    }
    else
    {
        cout << -1 << "\n";
    }

    return 0;
}