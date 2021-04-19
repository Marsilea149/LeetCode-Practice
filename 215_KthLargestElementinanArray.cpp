class Solution
{
public:
    int findKthLargest(vector<int> &nums, int k)
    {
        // Declare an descending priority queue
        std::priority_queue<int> q;
        for (int i = 0; i < nums.size(); ++i)
        {
            q.push(nums[i]);
        }
        for (int i = 1; i < k; ++i)
        {
            q.pop();
        }
        return q.top();
    }
};

//Better solution
class Solution
{
public:
    int findKthLargest(vector<int> &nums, int k)
    {
        // Declare an ascending priority queue
        std::priority_queue<int, std::vector<int>, std::greater<int>> pq;
        for (int i = 0; i < nums.size(); ++i)
        {
            pq.push(nums[i]);
            /** when the size of the queue is larger than k, we can remove the top one,
             * which is the smallest number n the queue
             */
            if (pq.size() > k)
            {
                pq.pop();
            }
        }
        return pq.top();
    }
};