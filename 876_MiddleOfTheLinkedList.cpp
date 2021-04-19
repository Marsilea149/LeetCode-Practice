#include <iostream>
#include <vector>
#include <unordered_map>
#include <map>
#include <string>

// Huahua's solution
ListNode *middleNode(ListNode *head)
{
    if (!head || !head->next)
        return head;
    auto slow = head;
    auto fast = head;
    while (fast && fast->next)
    {
        slow = slow->next;
        fast = fast->next->next;
    }
    return slow;
}

int main()
{
    n = new ListNode;

    ListNode *ans = middleNode(n);
}

//////SOLUTION FROM LEETCODE///////

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution
{
public:
    ListNode *middleNode(ListNode *head)
    {
        vector<ListNode *> A = {head};
        while (A.back()->next != NULL)
            A.push_back(A.back()->next);
        return A[A.size() / 2];
    }
};

/*
class Solution {
public:
    ListNode* middleNode(ListNode* head) {
        ListNode* slow = head;
        ListNode* fast = head;
        while (fast != NULL && fast->next != NULL) {
            slow = slow->next;
            fast = fast->next->next;
        }
        return slow;
    }
};
*/