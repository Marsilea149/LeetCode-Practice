
#include <iostream>
#include <vector>
#include <unordered_map>
#include <string>
#include <utility>
#include <algorithm>
#include <map>

using namespace std;

vector<vector<string>> groupAnagrams(vector<string> &strs)
{
    unordered_map<int, vector<string>> res;
    map<string, int> key; //
    int cnt = 0;          // Number of groups of anagrams
    for (int i = 0; i < strs.size(); i++)
    {
        string cur = strs[i];
        sort(cur.begin(), cur.end()); //sorted current string
        if (key.find(cur) == key.end())
        {
            // "cur" not found in "key"
            key[cur] = cnt;              //create a new anagram group
            res[cnt].push_back(strs[i]); // store the current string into this anagram group
            cnt++;                       //update the anagram group index for next iteration
        }
        else
        {
            // "cur" is an existing "key", there is already a matched anagram group
            res[key[cur]].push_back(strs[i]); // store the string into the right anagram group
        }
    }
    vector<vector<string>> fin;
    for (auto it = res.begin(); it != res.end(); it++)
    {
        // store the anagram groups into the resulting vector
        fin.push_back(it->second);
    }
    return fin;
}

int main()
{
    std::string input[] = {"bob", "boo", "eat", "tea", "tan", "ate", "nat", "bat"};
    std::vector<std::string> inputVector;
    int n = sizeof(input) / sizeof(input[0]);
    for (int i = 0; i < n; ++i)
    {
        inputVector.push_back(input[i]);
    }
    for (int i = 0; i < inputVector.size(); ++i)
    {
        std::cout << "input[" << i << "] = " << inputVector.at(i) << std::endl;
    }
    std::vector<std::vector<std::string>> output = groupAnagrams(inputVector);
    for (int i = 0; i < output.size(); ++i)
    {
        std::cout << "output[" << i << "] = " << std::endl;
        for (int j = 0; j < output.at(i).size(); ++j)
        {
            std::vector<std::string> curVect = output.at(i);
            std::cout << "[" << curVect.at(j) << "]" << std::endl;
        }
    }
    return 0;
}
