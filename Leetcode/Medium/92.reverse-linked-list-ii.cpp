/*
 * @lc app=leetcode id=92 lang=cpp
 *
 * [92] Reverse Linked List II
 *
 * https://leetcode.com/problems/reverse-linked-list-ii/description/
 *
 * algorithms
 * Medium (43.49%)
 * Likes:    7398
 * Dislikes: 322
 * Total Accepted:    540.6K
 * Total Submissions: 1.2M
 * Testcase Example:  '[1,2,3,4,5]\n2\n4'
 *
 * Given the head of a singly linked list and two integers left and right where
 * left <= right, reverse the nodes of the list from position left to position
 * right, and return the reversed list.
 *
 *
 * Example 1:
 *
 *
 * Input: head = [1,2,3,4,5], left = 2, right = 4
 * Output: [1,4,3,2,5]
 *
 *
 * Example 2:
 *
 *
 * Input: head = [5], left = 1, right = 1
 * Output: [5]
 *
 *
 *
 * Constraints:
 *
 *
 * The number of nodes in the list is n.
 * 1 <= n <= 500
 * -500 <= Node.val <= 500
 * 1 <= left <= right <= n
 *
 *
 *
 * Follow up: Could you do it in one pass?
 */

// @lc code=start
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
#include <bits/stdc++.h>
using namespace std;

void reverse(ListNode *&head, ListNode *afterend)
{
    ListNode *ptr = afterend, *temp = head->next;

    while (temp != afterend)
    {
        head->next = ptr;
        ptr = head;
        head = temp;
        temp = head->next;
    }

    head->next = ptr;
}

class Solution
{
public:
    ListNode *reverseBetween(ListNode *head, int left, int right)
    {

        if (left == right || !head->next)
        {
            return head;
        }

        int c = 1;
        ListNode *start, *end, *afterend, *beforestart;

        if (left == 1)
        {
            start = head;
        }

        ListNode *temp = head;

        while (temp)
        {
            if (c == left - 1)
            {
                beforestart = temp;
            }

            c++;
            temp = temp->next;

            if (c == left)
            {
                start = temp;
            }

            if (c == right)
            {
                end = temp;
                afterend = temp->next;
                break;
            }
        }

        reverse(start, afterend);

        if (left != 1)
        {
            beforestart->next = start;
        }
        else
        {
            head = start;
        }

        return head;
    }
};
// @lc code=end
