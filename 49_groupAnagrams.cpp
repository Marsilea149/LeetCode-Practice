#include <iostream>
#include <vector>
#include <unordered_map>
#include <string>
#include <utility>
#include <algorithm>
#include <map>

std::vector<std::vector<std::string>> groupAnagrams(std::vector<std::string> &strs);

std::vector<std::vector<std::string>> groupAnagrams(std::vector<std::string> &strs)
{

    // map: a vector storing the unordered_map for each string
    std::vector<std::unordered_map<char, int>> unorderedMap(strs.size());
    std::vector<std::map<char, int>> orderedMap;

    for (int i = 0; i < strs.size(); ++i)
    {

        // generate one map for each string
        for (const auto &c : strs[i])
        {
            //Add if loop to check if c already appeared
            if (unorderedMap.at(i)[c])
            {
                std::cout << unorderedMap.at(i)[c];
                unorderedMap.at(i)[c] = unorderedMap.at(i)[c] + 1;
                std::pair<char, int> p = std::make_pair(c, unorderedMap.at(i)[c]);
                // mark current char is present in unorderedMap.at(i) = curUnorderedMap
                unorderedMap.at(i).insert(p);
            }
            else
            {
                unorderedMap.at(i)[c] = 1;
                std::pair<char, int> p = std::make_pair(c, unorderedMap.at(i)[c]);
                // mark current char is present in unorderedMap.at(i) = curUnorderedMap
                unorderedMap.at(i).insert(p);
            }
        }
    }

    // convert unorderedMap into an orderedMap
    // ordered_map
    for (int i = 0; i < strs.size(); ++i)
    {
        std::unordered_map<char, int> curUnorderedMap = unorderedMap.at(i);
        std::map<char, int> curOrderedMap(curUnorderedMap.begin(), curUnorderedMap.end());
        orderedMap.push_back(curOrderedMap);
        // for (auto it = curOrderedMap.begin(); it != curOrderedMap.end(); ++it)
        //     std::cout << "orderdMap[" << it->first << "]=>" << it->second << std::endl;
    }

    // declare the ans vector: vector of strings belong to the same anagrams
    std::vector<std::vector<std::string>> ans;
    //  vector indicating if the current string is already in one anagram group
    std::vector<bool> inAlready(strs.size(), false);

    for (int i = 0; i < orderedMap.size(); ++i)
    {
        for (int j = i + 1; j < strs.size(); ++j)
        {
            // check if strs[j] is already in one group, go only both elements have not been added into any group
            if (!(inAlready.at(j) && inAlready.at(i)))
            {
                // save matched string into the currentGroup
                if (orderedMap.at(i) == orderedMap.at(j))
                {
                    // find the group in which strs(i) belongs to
                    std::string key = strs.at(i);
                    // present is a boolean variable indicating if the current string(key) is present in any group
                    bool present = false;
                    for (int k = 0; k < ans.size(); ++k)
                    {
                        std::vector<std::string> existingGroup = ans.at(k);
                        std::vector<std::string>::iterator itr = std::find(existingGroup.begin(), existingGroup.end(), key);
                        if (itr != existingGroup.cend())
                        {
                            // std::cout << "Element present at index " << std::distance(existingGroup.begin(), itr);
                            if (!(inAlready.at(j)))
                            {
                                // add the string at index j into the corresponding existing group in ans
                                ans.at(k).push_back(strs.at(j));
                                // remove the string from input list
                                inAlready.at(j) = true;
                                present = true;
                            }
                        }
                    }
                    // key is not present in any group yet
                    if (!present)
                    {
                        std::cout << "Creating new group containg:" << key << std::endl;
                        // create a vector of strings storing the strings below to the same anagram group
                        std::vector<std::string> currentGroup;
                        currentGroup.push_back(key);
                        // check if strs[j] is already in one group
                        if (!(inAlready.at(j)))
                        {
                            std::string key2 = strs.at(j);
                            currentGroup.push_back(key2);
                            inAlready.at(j) = true;
                        }
                        //Save the current group into the ans vector
                        ans.push_back(currentGroup);
                        // remove the string from input list
                        inAlready.at(i) = true;
                    }
                }
            }
        }
        // In case the last element does not bellow to any of previous existing groups
        if (!(inAlready.at(i)))
        {
            // find the group in which strs(i) belongs to
            std::string key = strs.at(i);
            std::cout << "Creating new group containg:" << key << std::endl;
            // create a vector of strings storing the strings below to the same anagram group
            std::vector<std::string> currentGroup;
            currentGroup.push_back(key);
            //Save the current group into the ans vector
            ans.push_back(currentGroup);
            // remove the string from input list
            inAlready.at(i) = true;
        }
    }
    return ans;
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
