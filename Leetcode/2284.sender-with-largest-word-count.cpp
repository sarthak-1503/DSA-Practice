#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    
    string largestWordCount(vector<string>& messages, vector<string>& senders) {
        int n = messages.size();
        int maxWords = 0;
        string maxSender = "";
        map<string,int,greater<string>> m;
        
        for(int i=0;i<n;i++)
        {
            stringstream str(messages[i]);
            string s;
            int c = 0;
            
            while(str >> s)
            {
                c++;
            }
            
            m[senders[i]] += c;
        }
        
        for(auto ptr : m)
        {
            if(maxWords < ptr.second)
            {
                maxSender = ptr.first;
                maxWords = ptr.second;
            }
        }
        
        
        
        return maxSender;
    }
};