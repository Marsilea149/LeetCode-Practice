//Solution from huahua
//Difficulty: 7/10
//Attention to difference between permutation and combination
//s : represent from which value we do the test of sum,
class Solution
{
public:
    vector<vector<int>> combinationSum(vector<int> &candidates, int target)
    {
        //sort candidates from small to big
        std::sort(candidates.begin(), candidates.end());

        //dfs applied to target with criteria of sum
        //when sum is larger than target, stop dfs
        vector<vector<int>> res;
        vector<int> temp;
        dfs(candidates, target, 0, temp, res);
        return res;
    }

private:
    void dfs(vector<int> const &candidates,
             int target, int s, vector<int> &temp, vector<vector<int>> &res)
    {
        if (target == 0)
        {
            res.push_back(temp);
            return;
        }

        for (int i = s; i < candidates.size(); ++i)
        {

            if (candidates[i] > target)
            {
                break;
            }

            temp.push_back(candidates[i]);
            //if dfs(candidates, target - candidates[i], s, temp, res); it become a permutation solution
            //with i, the search only concern the values not used yet!
            dfs(candidates, target - candidates[i], i, temp, res);
            temp.pop_back();
        }
    }
};