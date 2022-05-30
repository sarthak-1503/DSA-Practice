#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool digitCount(string num) {
        int n = num.size();
        map<int,int> m;
        
        for(int i=0;i<n;i++)
        {
            m[num[i]-'0']++;
        }
        
        for(int i=0;i<n;i++)
        {
            
            if(m[i] != num[i]-'0')
            {
                return false;
            }
        }
        
        return true;
    }
};