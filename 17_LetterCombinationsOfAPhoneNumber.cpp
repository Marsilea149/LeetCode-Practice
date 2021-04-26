class Solution
{
public:
    vector<string> letterCombinations(string digits)
    {
        if (digits.empty())
            return {};
        std::vector<std::vector<char>> m(10);
        m[0] = {' '};
        m[1] = {};
        m[2] = {'a', 'b', 'c'};
        m[3] = {'d', 'e', 'f'};
        m[4] = {'g', 'h', 'i'};
        m[5] = {'j', 'k', 'l'};
        m[6] = {'m', 'n', 'o'};
        m[7] = {'p', 'q', 'r', 's'};
        m[8] = {'t', 'u', 'v'};
        m[9] = {'w', 'x', 'y', 'z'};

        string cur;
        std::vector<string> res;
        dfs(digits, m, 0, cur, res);
        return res;
    }

    void dfs(string const &digits, std::vector<std::vector<char>> const &m,
             int l, string &cur, std::vector<string> &res)
    {
        if (l == digits.length())
        {
            res.push_back(cur);
            return;
        }

        for (const char c : m[digits[l] - '0'])
        {
            cur.push_back(c);
            dfs(digits, m, l + 1, cur, res);
            cur.pop_back();
        }
    }
};