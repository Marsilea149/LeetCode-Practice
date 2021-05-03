// 42. Trapping Rain Water
// Hard
// Given n non-negative integers representing an elevation map where the width of each bar is 1, compute how much water it can trap after raining.

// Example 1:

// Input: height = [0,1,0,2,1,0,1,3,2,1,2,1]
// Output: 6
// Explanation: The above elevation map (black section) is represented by array [0,1,0,2,1,0,1,3,2,1,2,1]. In this case, 6 units of rain water (blue section) are being trapped.
// Example 2:

// Input: height = [4,2,0,3,2,5]
// Output: 9

// Constraints:

// n == height.length
// 0 <= n <= 3 * 104
// 0 <= height[i] <= 105

// Solution from https://zxi.mytechroad.com/blog/dynamic-programming/leetcode-42-trapping-rain-water/
// brute force
// complexity: time (n^2), space (1)
class Solution
{
public:
    int trap(vector<int> &height)
    {
        const int n = height.size();
        int ans = 0;
        auto sit = cbegin(height);
        auto eit = cend(height);
        for (int i = 0; i < n; ++i)
        {
            // left upper bound value: the highest height value for i between [0; i + 1)
            int l = *max_element(sit, sit + i + 1);
            // right upper bound value: the highest height value for i between [i; n)
            int r = *max_element(sit + i, eit);
            // the accumulated water at i (r[i]): lower bound - its own height
            // r[i] = min( max(h[0~i]), max(h[i~(n-1)]) ) - h[i]
            // sum over r[i] is the total accumulated water
            ans += min(l, r) - height[i];
        }
        return ans;
    }
};