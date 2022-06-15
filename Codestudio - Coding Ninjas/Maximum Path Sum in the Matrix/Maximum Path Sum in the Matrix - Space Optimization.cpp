// https://www.codingninjas.com/codestudio/problems/maximum-path-sum-in-the-matrix_797998

#include<bits/stdc++.h>
using namespace std;

int getMaxPathSum(vector<vector<int>> &matrix)
{
    //  Write your code here.
    int m = matrix.size();
    int n = matrix[0].size();
    vector<int> prev = matrix[m-1];
    vector<int> curr = matrix[m-1];
    
    for(int i=m-2;i>=0;i--)
    {
        curr = vector<int> (n,-1);
        
        for(int j=0;j<n;j++)
        {
            curr[j] = matrix[i][j]+prev[j];
            
            if(j > 0)
            {
                curr[j] = max(curr[j],matrix[i][j] + prev[j-1]);
            }
            
            if(j < n-1)
            {
                curr[j] = max(curr[j],matrix[i][j] + prev[j+1]);
            }
        }
        
        prev = curr;
    }
    
    return *max_element(curr.begin(),curr.end());
}