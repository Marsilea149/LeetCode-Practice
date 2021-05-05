//Code from Huahua: https://zxi.mytechroad.com/blog/algorithms/array/leetcode-315-count-of-smaller-numbers-after-self/
//Difficulty: 9/10
//Key: Binary Indexed Tree or FenwickTree
//complexity: nlog(n)

class FenwickTree
{
public:
    FenwickTree(int n)
        : sums_(n + 1, 0)
    {
    }

    void update(int i, int delta)
    {
        while (i < sums_.size())
        {
            sums_[i] += delta;
            i += lowbit(i);
        }
    }

    int query(int i) const
    {
        int sum = 0;
        while (i > 0)
        {
            sum += sums_[i];
            i -= lowbit(i);
        }
        return sum;
    }

private:
    static inline int lowbit(int x)
    {
        return x & (-x);
    }

    vector<int> sums_;
};

class Solution
{
public:
    vector<int> countSmaller(vector<int> &nums)
    {
        //sort the unique numbers
        set<int> sorted(nums.begin(), nums.end());
        //map the number to its rank
        unordered_map<int, int> ranks;
        int rank = 0;
        for (int const num : sorted)
        {
            ranks[num] = ++rank;
        }

        vector<int> res;
        FenwickTree tree(nums.size());
        //scan the numbers in reversed order
        for (int i = nums.size() - 1; i >= 0; --i)
        {
            //check how many numbers are smaller than the current number
            res.push_back(tree.query(ranks[nums[i]] - 1));
            //increase the count of the rank of current number
            tree.update(ranks[nums[i]], 1);
        }

        std::reverse(res.begin(), res.end());
        return res;
    }
};