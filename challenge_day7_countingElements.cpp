#include <iostream>
#include <vector>
#include <unordered_map>
#include <map>
#include <string>

// using namespace std;

int countElements(std::vector<int>& arr) {

    std::unordered_map<int, int> unorderedMap;

    // create a hashset of arr
    for(int i=0; i<arr.size(); ++i)
    {
        int key = arr[i];
        if (unorderedMap.find(key) == unorderedMap.end())
        {
            std::pair<int, int> p = std::make_pair(key, 1);
            unorderedMap.insert(p);
        }
        else      
        {   
            // unorderedMap[key] += 1;
            unorderedMap.at(key) += 1;
        }
    }

    // Sort the unorderedMap to be orderedMap   
    std::map<int, int> orderedMap(unorderedMap.begin(), unorderedMap.end());

    int ans = 0;
    // loop through to find valid integers
    for (std::map<int, int>::iterator itr = orderedMap.begin(); itr != orderedMap.end(); itr++) 
    {
        int key = itr->first + 1;
        if (orderedMap.find(key) != orderedMap.end())
        {
            int origin = orderedMap.find(itr->first)->second;
            ans += origin;
        }
    }
    return ans;
}

int main()
{
    // --- INPUT SETTING --- //
    int input[] = {1,3,2,3,5,0};
    std::vector<int> inputVector;
    int n = sizeof(input) / sizeof(input[0]);
    for (int i = 0; i < n; ++i)
    {
        inputVector.push_back(input[i]);
    }
    for (int i = 0; i < inputVector.size(); ++i)
    {
        std::cout << "input[" << i << "] = " << inputVector.at(i) << std::endl;
    }

    // --- OUTUT SETTING --- //
    int output = countElements(inputVector);
    std::cout << "output =" << output << std::endl;

    return 0;
}
