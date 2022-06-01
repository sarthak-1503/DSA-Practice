#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int percentageLetter(string s, char letter) {
        int n =  s.size();
        int cnt = count(s.begin(),s.end(),letter);
        int perc = (cnt*100)/n;
        
        return perc;
    }
};