/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution
{
public:
    Node *copyRandomList(Node *head)
    {
        if (!head)
            return nullptr;

        unordered_set<Node *> done;
        unordered_map<Node *, Node *> m;
        queue<Node *> q;
        q.push(head);
        while (!q.empty())
        {
            //update the current node to proceed
            Node *cur = q.front();
            q.pop();

            //keep track of already preceeded node
            if (done.count(cur))
                continue;
            done.insert(cur);

            //update the map with current node
            if (!(m.count(cur)))
                m[cur] = new Node(cur->val);
            Node *t = m[cur];

            //update the map with the current node's next node
            if (!cur->next)
                m[cur->next] = nullptr;
            else
            {
                Node *curNext = cur->next;
                if (!(m.count(curNext)))
                    m[curNext] = new Node(curNext->val);
                q.push(curNext);
                t->next = m[curNext];
            }

            //update the map with the current node's random node
            if (!cur->random)
                m[cur->random] = nullptr;
            else
            {
                Node *curRand = cur->random;
                if (!(m.count(curRand)))
                    m[curRand] = new Node(curRand->val);
                q.push(curRand);
                t->random = m[curRand];
            }
        }
        return m[head];
    }
};