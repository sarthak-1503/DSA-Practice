// https://www.codingninjas.com/codestudio/problems/check-graph-is-bipartite-or-not_920551

#include<bits/stdc++.h>
using namespace std;

bool DFS(int node,int parent,vector<int> &color,vector<vector<int>> &graph,int V)
{
    if(color[node] == -1)
    {
        if(parent != -1)
        {
            color[node] = color[parent] ^ 1;
        }
        else
        {
            color[node] = 0;
        }
    }

    for(int i=0;i<V;i++)
    {
        if(graph[node][i] == 1)
        {
            if(color[i] == -1)
            {
                color[i] = color[node] ^ 1;

                if(!DFS(i,node,color,graph,V))
                {
                    return false;
                }
            }
            else if(i != parent && color[i] == color[node])
            {
                return false;
            }
        }
    }

    return true;
}

bool isGraphBirpatite(vector<vector<int>> &graph) {
	// Write your code here.
    int V = graph.size();
    
    for(int i=0;i<V;i++)
    {
        for(int j=0;j<V;j++)
        {
            if(graph[i][j] == 1)
            {
                graph[j][i] = 1;
            }
        }
    }
    
    vector<int> color(V,-1);

    for(int i=0;i<V;i++)
    {
        if(color[i] == -1 && !DFS(i,-1,color,graph,V))
        {
            return false;
        }
    }

    return true;
}