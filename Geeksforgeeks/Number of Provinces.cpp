// https://practice.geeksforgeeks.org/problems/number-of-provinces/1/#

#include<bits/stdc++.h>
using namespace std;

class Solution {
  public:
  
    void noOfComponents(vector<bool> &visited,vector<vector<int>> &adj,int node,int V)
    {
        for(int i=0;i<V;i++)
        {
            if(adj[node][i] == 1 && !visited[i])
            {
                visited[i] = true;
                noOfComponents(visited,adj,i,V);
            }
        }
    }
  
    int numProvinces(vector<vector<int>> adj, int V) {
        // code here
        vector<bool> visited(V,false);
        int ans = 0;
        
        
        for(int i=0;i<V;i++)
        {
            if(visited[i] == false)
            {
                ans++;
                noOfComponents(visited,adj,i,V);
            }
        }
        
        return ans;
    }
};