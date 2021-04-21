class Solution
{
public:
    int findMin(vector<int> &nums)
    {
        return findMinVal(nums, 0, nums.size() - 1);
    }

    int findMinVal(vector<int> &nums, int i, int j)
    {
        // if the size of the segment is 2 or 1, return the min
        if (j - i <= 1)
            return min(nums[i], nums[j]);

        // take the middle of the segment
        int m = i + floor((j - i) / 2);
        int left = 0;
        int right = 0;

        if (nums[i] < nums[m])
            left = nums[i];
        else
            left = findMinVal(nums, i, m);

        if (nums[m + 1] < nums[j])
            right = nums[m + 1];
        else
            right = findMinVal(nums, m + 1, j);

        return min(left, right);
    }
};

/**
 *  We can regroup the comparison for sorted part, return directly when sorted
 */
class Solution
{
public:
    int findMin(vector<int> &nums)
    {
        return findMinVal(nums, 0, nums.size() - 1);
    }

    int findMinVal(vector<int> &nums, int i, int j)
    {
        // if the size of the segment is 2 or 1, return the min
        if (j - i <= 1)
            return min(nums[i], nums[j]);

        // sorted
        if (nums[i] < nums[j])
            return nums[i];

        // take the middle of the segment
        // Here floor is not necessary because, i and j are both int, i/j means i divide by j
        int m = i + (j - i) / 2;
        int left = findMinVal(nums, i, m);
        int right = findMinVal(nums, m + 1, j);
        return min(left, right);
    }
};