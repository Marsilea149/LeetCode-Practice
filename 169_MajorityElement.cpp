/**
 * Solution with divid and conquer, time exceed limitation!!! 
 */

class Solution
{
public:
    int majorityElement(vector<int> &nums)
    {
        int n = nums.size();
        return dfs(nums, 0, n - 1);
    }

    int dfs(vector<int> &nums, int i, int j)
    {
        if (i == j)
        {
            return nums[i];
        }

        int m = floor((i + j) / 2);
        int left = dfs(nums, i, m);
        int right = dfs(nums, m + 1, j);
        if (left == right)
        {
            return left;
        }
        int leftCount = count(nums, i, m, left);
        int rightCount = count(nums, m + 1, j, right);
        if (leftCount > rightCount)
            return left;
        else
            return right;
    }

    int count(vector<int> &nums, int i, int j, int c)
    {
        int res = 0;
        for (int k = 0; k < j; ++k)
        {
            if (nums[k] == c)
                res++;
        }
        return res;
    }
};

/**
 * Solution works because there are for sure more than n/2 elements in the vector which are
 * the same, so even we remove n/2 elements, the left element will be the majority element
 */
class Solution
{
public:
    int majorityElement(vector<int> &nums)
    {
        int majority = nums[0];
        int count = 1;
        for (int i = 1; i < nums.size(); ++i)
        {
            if (nums[i] == majority)
            {
                count++;
            }
            else
            {
                count--;
                if (count == 0)
                {
                    majority = nums[i];
                    count = 1;
                }
            }
        }
        return majority;
    }
};