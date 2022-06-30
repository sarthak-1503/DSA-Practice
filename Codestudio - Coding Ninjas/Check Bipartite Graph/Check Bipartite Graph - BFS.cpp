// https://www.codingninjas.com/codestudio/problems/check-graph-is-bipartite-or-not_920551

#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pi;

bool BFS(int node, int parent, vector<int> &color, vector<vector<int>> &edges, int V)
{
    queue<pi> q;
    q.push({node, -1});
    color[node] = 0;

    while (!q.empty())
    {
        int currnode = q.front().first;
        int currparent = q.front().second;
        q.pop();

        for (int i = 0; i < V; i++)
        {
            if (edges[currnode][i] == 1)
            {
                if (color[i] == -1)
                {
                    color[i] = color[currnode] ^ 1;
                    q.push({i, currnode});
                }
                else if (i != currparent && color[i] == color[currnode])
                {
                    return false;
                }
            }
        }
    }

    return true;
}

bool isGraphBirpatite(vector<vector<int>> &edges)
{
    // Write your code here.
    int V = edges.size();
    vector<int> color(V, -1);

    for (int i = 0; i < V; i++)
    {
        for (int j = 0; j < V; j++)
        {
            edges[j][i] = edges[i][j];
        }
    }

    for (int i = 0; i < V; i++)
    {
        if (color[i] == -1 && !BFS(i, -1, color, edges, V))
        {
            return false;
        }
    }

    return true;
}