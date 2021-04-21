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
        stack<int> s1;
        stack<int> s2;
        stack<int> s3;
        while (l1 || l2)
        {
            if (l1)
            {
                s1.push(l1->val);
                l1 = l1->next;
            }

            if (l2)
            {
                s2.push(l2->val);
                l2 = l2->next;
            }
        }

        int carry = 0;
        ListNode *tail = new ListNode(0);
        ListNode *dummy = tail;

        while (!s1.empty() || !s2.empty() || carry)
        {
            int sum = 0;
            if (!s1.empty())
            {
                sum += s1.top();
                s1.pop();
            }
            if (!s2.empty())
            {
                sum += s2.top();
                s2.pop();
            }
            sum += carry;

            s3.push(sum % 10);
            // update for next iteration
            carry = sum / 10;
        }

        while (!s3.empty())
        {
            tail->next = new ListNode(s3.top());
            s3.pop();
            tail = tail->next;
        }

        return dummy->next;
    }
};

/**
 * Better solution: without the final stack!!!
 */

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
        stack<int> s1;
        stack<int> s2;
        stack<int> s3;
        while (l1 || l2)
        {
            if (l1)
            {
                s1.push(l1->val);
                l1 = l1->next;
            }

            if (l2)
            {
                s2.push(l2->val);
                l2 = l2->next;
            }
        }

        int carry = 0;
        ListNode *head = nullptr;

        while (!s1.empty() || !s2.empty() || carry)
        {
            int sum = 0;
            if (!s1.empty())
            {
                sum += s1.top();
                s1.pop();
            }
            if (!s2.empty())
            {
                sum += s2.top();
                s2.pop();
            }
            sum += carry;

            ListNode *n = new ListNode(sum % 10);

            // update for next iteration
            carry = sum / 10;
            n->next = head;
            head = n;
        }

        return head;
    }
};