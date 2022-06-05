/*
 * @lc app=leetcode id=2276 lang=cpp
 *
 * [2276] Count Integers in Intervals
 *
 * https://leetcode.com/problems/count-integers-in-intervals/description/
 *
 * algorithms
 * Hard (28.88%)
 * Likes:    237
 * Dislikes: 35
 * Total Accepted:    7K
 * Total Submissions: 23.4K
 * Testcase Example:  '["CountIntervals","add","add","count","add","count"]\n[[],[2,3],[7,10],[],[5,8],[]]'
 *
 * Given an empty set of intervals, implement a data structure that can:
 * 
 * 
 * Add an interval to the set of intervals.
 * Count the number of integers that are present in at least one interval.
 * 
 * 
 * Implement the CountIntervals class:
 * 
 * 
 * CountIntervals() Initializes the object with an empty set of intervals.
 * void add(int left, int right) Adds the interval [left, right] to the set of
 * intervals.
 * int count() Returns the number of integers that are present in at least one
 * interval.
 * 
 * 
 * Note that an interval [left, right] denotes all the integers x where left <=
 * x <= right.
 * 
 * 
 * Example 1:
 * 
 * 
 * Input
 * ["CountIntervals", "add", "add", "count", "add", "count"]
 * [[], [2, 3], [7, 10], [], [5, 8], []]
 * Output
 * [null, null, null, 6, null, 8]
 * 
 * Explanation
 * CountIntervals countIntervals = new CountIntervals(); // initialize the
 * object with an empty set of intervals. 
 * countIntervals.add(2, 3);  // add [2, 3] to the set of intervals.
 * countIntervals.add(7, 10); // add [7, 10] to the set of intervals.
 * countIntervals.count();    // return 6
 * ⁠                          // the integers 2 and 3 are present in the
 * interval [2, 3].
 * ⁠                          // the integers 7, 8, 9, and 10 are present in
 * the interval [7, 10].
 * countIntervals.add(5, 8);  // add [5, 8] to the set of intervals.
 * countIntervals.count();    // return 8
 * ⁠                          // the integers 2 and 3 are present in the
 * interval [2, 3].
 * ⁠                          // the integers 5 and 6 are present in the
 * interval [5, 8].
 * ⁠                          // the integers 7 and 8 are present in the
 * intervals [5, 8] and [7, 10].
 * ⁠                          // the integers 9 and 10 are present in the
 * interval [7, 10].
 * 
 * 
 * 
 * Constraints:
 * 
 * 
 * 1 <= left <= right <= 10^9
 * At most 10^5 calls in total will be made to add and count.
 * At least one call will be made to count.
 * 
 * 
 */

// @lc code=start
#include<bits/stdc++.h>
using namespace std;

bool isOverlapping(int a1,int b1,int a2,int b2)
{
    return ((a1 >= a2 && a1 <= b2) || (a2 >= a1 && a2 <= b1));
}

class CountIntervals {
public:

    map<long,long> m;
    long cnt;

    CountIntervals() {
        m.clear();
        cnt = 0;
    }
    
    void add(int left, int right) {
        m[left] = right;
        auto ptr = m.find(left);
        auto ptrnext = m.upper_bound(left);
        auto ptrprev = prev(ptr);
        int initLeft = left;
        int initRight = right;
        int flag = 0;

        if(ptr != m.begin() && isOverlapping(left,right,ptrprev->first,ptrprev->second))
        {
            flag = 1;

            if(right <= ptrprev->second)
            {
                m.erase(initLeft);
                return ;
            }
            else
            {
                m.erase(ptrprev->first);
                m[min((long)left,ptrprev->first)] = max((long)right,ptrprev->second);
                cnt += (ptrprev->second - min((long)left,ptrprev->first) - (ptrprev->second - ptrprev->first));
                left = ptrprev->second + 1;
            }
        }

        if(ptrnext != m.end() && isOverlapping(left,right,ptrnext->first,ptrnext->second))
        {
            flag = 1;

            if(right >= ptrnext->second)
            {
                cnt += ((right - left) - (ptrnext->second - ptrnext->first));
                m.erase(initLeft);
                return ;
            }
            else
            {
                m.erase(ptrnext->first);
                m[min((long)left,ptrnext->first)] = max((long)right,ptrnext->second);
                cnt += (max((long)right,ptrnext->second) - ptrnext->first - (ptrnext->second - ptrnext->first));
                right = ptrnext->first - 1;
            }
        }

        m.erase(initLeft);

        if(left > right)
        {
            return ;
        }

        m[left] = right;
        
        if(flag == 0)
        {
            cnt += (right - left + 1);
        }

        cout<<initLeft<<" "<<initRight<<" "<<cnt<<"\n";
    }
    
    int count() {
        return cnt;
    }
};

/**
 * Your CountIntervals object will be instantiated and called as such:
 * CountIntervals* obj = new CountIntervals();
 * obj->add(left,right);
 * int param_2 = obj->count(); 
 */
// @lc code=end

