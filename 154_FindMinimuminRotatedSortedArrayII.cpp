class Solution
{
public:
    int findMin(vector<int> &nums)
    {
        return findMin(nums, 0, nums.size() - 1);
    }

    int findMin(vector<int> &nums, int l, int r)
    {
        //length smaller than 2
        if ((r - l) <= 1)
        {
            return min(nums[l], nums[r]);
        }

        //sorted
        if (nums[l] < nums[r])
            return nums[l];

        //not sorted, divid with the mid point
        int m = l + (r - l) / 2;

        return min(findMin(nums, l, m), findMin(nums, m + 1, r));
    }
};