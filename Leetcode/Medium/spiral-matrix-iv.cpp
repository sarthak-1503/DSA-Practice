
// * @lc app=leetcode id=2326 lang=cpp

// @lc code=start
#include <bits/stdc++.h>
using namespace std;

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution
{
public:
    void traverseRow(int row, int start, int end, int dir, vector<vector<int>> &ans, ListNode *&head)
    {
        if (dir == 1)
        {
            for (int i = start; i <= end; i++)
            {
                ans[row][i] = head->val;
                head = head->next;

                if (head == NULL)
                {
                    return;
                }
            }
        }
        else
        {
            for (int i = end; i >= start; i--)
            {
                ans[row][i] = head->val;
                head = head->next;

                if (head == NULL)
                {
                    return;
                }
            }
        }
    }

    void traverseCol(int col, int start, int end, int dir, vector<vector<int>> &ans, ListNode *&head)
    {
        if (dir == 1)
        {
            for (int i = start; i <= end; i++)
            {
                if (head == NULL)
                {
                    return;
                }

                ans[i][col] = head->val;
                head = head->next;
            }
        }
        else
        {
            for (int i = end; i >= start; i--)
            {
                if (head == NULL)
                {
                    return;
                }

                ans[i][col] = head->val;
                head = head->next;
            }
        }
    }

    vector<vector<int>> spiralMatrix(int m, int n, ListNode *head)
    {
        vector<vector<int>> ans(m, vector<int>(n, -1));
        int startr = 0, startc = 1;
        int dir = -1;
        ListNode *temp = head;
        int origm = m, orign = n;

        while (m > 0 && n > 0 && temp)
        {
            dir = -dir;

            if (dir == 1)
            {
                traverseRow(startr, startr, n - 1, dir, ans, temp);
                traverseCol(n - 1, startc, m - 1, dir, ans, temp);
                m--;
                n--;
            }
            else
            {
                traverseRow(m, startr, n - 1, dir, ans, temp);
                traverseCol(startc - 1, startc, m - 1, dir, ans, temp);
                startr++;
                startc++;
            }

            //             for(int i=0;i<origm;i++)
            //             {
            //                 for(int j=0;j<orign;j++)
            //                 {
            //                     cout<<ans[i][j]<<" ";
            //                 }

            //                 cout<<"\n";
            //             }
            //             cout<<"\n";

            //             cout<<m<<" "<<n<<"\n";
        }

        while (m > 0 && temp)
        {
            dir = -dir;

            if (dir == 1)
            {
                traverseCol(n - 1, startc, m - 1, dir, ans, temp);
                m--;
                n--;
            }
            else
            {
                traverseCol(startc - 1, startc, m - 1, dir, ans, temp);
                startr++;
                startc++;
            }
        }

        while (n > 0 && temp)
        {
            dir = -dir;

            if (dir == 1)
            {
                traverseRow(startr, startr, n - 1, dir, ans, temp);
                m--;
                n--;
            }
            else
            {
                traverseRow(m, startr, n - 1, dir, ans, temp);
                startr++;
                startc++;
            }
        }

        return ans;
    }
};

// @lc code=end