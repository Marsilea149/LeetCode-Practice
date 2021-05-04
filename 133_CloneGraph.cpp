/**Difficulty: 9/10
 * Key notion: hashtable
 * creat a hashtable with the original nodes as keys, build the new nodes
 */

/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution
{
public:
    Node *cloneGraph(Node *node)
    {
        if (!node)
            return nullptr;
        unordered_set<Node *> done;
        unordered_map<Node *, Node *> m;
        queue<Node *> q;
        q.push(node);
        while (!q.empty())
        {
            Node *s = q.front();
            q.pop();
            if (done.count(s))
                continue;
            done.insert(s);
            // in the unordered_map, if the node does not exist, creat it
            if (!m.count(s))
                m[s] = new Node(s->val);
            Node *t = m[s];
            for (Node *ss : s->neighbors)
            {
                if (!m.count(ss))
                    m[ss] = new Node(ss->val);
                q.push(ss);
                t->neighbors.push_back(m[ss]);
            }
        }
        return m[node];
    }
};