/**Solution from Huahua:
 *
 * Difficulty: 7/10 
 * use binary serach tree on [max weight, accumulated weight],
 * target = D, criteria is all weghts are sent
 */

class Solution
{
public:
    int shipWithinDays(vector<int> &weights, int D)
    {
        int l = *max_element(begin(weights), end(weights));
        int r = accumulate(begin(weights), end(weights), 0);
        while (l < r)
        {
            int m = l + (r - l) / 2;
            int d = 1;
            int t = 0;
            //send weight up to m per day, compute the number of days required
            for (int w : weights)
            {
                t = t + w;
                if (t > m)
                {
                    t = w;
                    ++d;
                }
            }
            //binary search to find to fin the weight per day
            if (d > D)
                l = m + 1;
            else
                r = m;
        }
        return l;
    }
};