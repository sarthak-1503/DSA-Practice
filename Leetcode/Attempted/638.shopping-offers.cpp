/*@lc app=leetcode id=638 lang=cpp

https://leetcode.com/problems/shopping-offers/description/*/    

// @lc code=start
#include<bits/stdc++.h>
using namespace std;

vector<int> operator - (vector<int> &a,vector<int> &b)
{
    vector<int> ans(a.size());

    for(int i=0;i<a.size();i++)
    {
        ans[i] = a[i] - b[i];
    }

    return ans;
}

class Solution {
public:

    bool isPossible(vector<int> needs,vector<int> &offer)
    {
        for(int i=0;i<needs.size();i++)
        {
            if(needs[i] < offer[i])
            {
                return false;
            }
        }

        return true;
    }

    int calcPrice(vector<int> needs, vector<int> &price)
    {
        long ans = 0;

        for(int i=0;i<needs.size();i++)
        {
            ans += needs[i]*price[i];
        }

        return ans;
    }


    int minTotalPrice(int index,vector<int> needs,vector<vector<int>>& special, vector<int> &price)
    {
        if(index < 0)
        {
            return INT_MAX;
        }

        // if(!isPossible(needs,special[index]))
        // {
        //     return ;
        // }

        int taken = INT_MAX, notTaken;
        notTaken = minTotalPrice(index-1,needs,special,price);

        if(isPossible(needs,special[index]))
        {
            taken = min(minTotalPrice(index-1,needs-special[index],special,price),minTotalPrice(index-1,needs-special[index],special,price));

            if(taken != INT_MAX)
            {
                taken += calcPrice(needs-special[index],price);
            }
        }
        else
        {
            taken = calcPrice(needs,price);
        }

        return min(taken,notTaken);
    }

    int shoppingOffers(vector<int>& price, vector<vector<int>>& special, vector<int>& needs) {
        int n = special.size();
        return minTotalPrice(n-1,needs,special,price);
    }
};
// @lc code=end