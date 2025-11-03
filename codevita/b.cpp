#include <bits/stdc++.h>
using namespace std;


void inorder(int node, int parent, map<int, vector<int>>& tree, vector<int>& inorder_result) {
    // Get children, sort, and skip parent
    vector<int> children;
    for (int child : tree[node]) {
        if (child != parent) children.push_back(child);
    }
    sort(children.begin(), children.end());

    if (children.size() >= 1) inorder(children[0], node, tree, inorder_result);

    inorder_result.push_back(node);

    if (children.size() >= 2) inorder(children[1], node, tree, inorder_result);
}

// Signature matches competitive platforms
int solve(vector<vector<int>>& matrix, int n, vector<int>& site_guardians, int m) {
    // Build the tree as adjacency list
    map<int, vector<int>> tree;
    for (int i = 0; i < n; ++i) {
        tree[i] = {};
    }

    for (auto& edge : matrix) {
        int u = edge[0], v = edge[1];
        tree[u].push_back(v);
        tree[v].push_back(u); // Bi-directional
    }

    vector<int> inorder_result;
    inorder(0, -1, tree, inorder_result); // Start from root node 0

    // m is 1-based; adjust for 0-based indexing
    int chosen = inorder_result[m - 1];
    return site_guardians[chosen];
}