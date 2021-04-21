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

/**
 * Time exceeded limit!!!
 */
class Solution
{
public:
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2)
    {
        ListNode dummy(0);
        ListNode *tail = &dummy;
        int sum = 0;
        while (l1 != nullptr || l2 != nullptr || sum > 0)
        {

            if (l1 == nullptr && l2 != nullptr)
                sum += l2->val;
            else if (l2 == nullptr && l1 != nullptr)
                sum += l1->val;
            else if (l1 != nullptr && l2 != nullptr)
                sum += l1->val + l2->val;

            // update the tail value
            tail->next = new ListNode(sum % 10);

            // update for next cycle
            tail = tail->next;
            sum = sum / 10;
            if (l1->next != nullptr)
                l1 = l1->next;
            if (l2->next != nullptr)
                l2 = l2->next;
        }
        return dummy.next;
    }
};

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
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2)
    {
        ListNode *dummy = new ListNode(0);
        ListNode *tail = dummy;
        int carry = 0;
        while (l1 || l2 || carry)
        {
            int val1 = l1 ? l1->val : 0;
            int val2 = l2 ? l2->val : 0;

            // update the tail value
            tail->next = new ListNode((val1 + val2 + carry) % 10);

            // update for next cycle
            tail = tail->next;
            carry = (val1 + val2 + carry) / 10;
            if (l1)
                l1 = l1->next;
            if (l2)
                l2 = l2->next;
        }
        return dummy->next;
    }
};