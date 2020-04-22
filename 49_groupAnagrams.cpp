#include <iostream>
#include <vector>
#include <unordered_map>
#include <string>
#include <utility>
#include <algorithm>
#include <map>

std::vector<std::vector<std::string>> groupAnagrams(std::vector<std::string>& strs);

std::vector<std::vector<std::string>> groupAnagrams(std::vector<std::string>& strs) {

    // map: a vector storing the unordered_map for each string
    std::vector< std::unordered_map<char, int> > map(strs.size());

    // ordered_map 
    std::vector< std::map<char, int> > orderedVector(strs.size());
    for(int i=0; i<strs.size(); ++i)
    {
        // generate one map for each string
        for(const auto &c:strs[i] )
        {
            //Add if loop to check if c already appeared
            std::cout << "c = " << c << std::endl;
            std::pair<char,int> p= std::make_pair(c, 1);

            // Display the content of each pair
            // std::cout << "pair[" << i << "] = " << std::endl;
            // std::cout << p.first << ", " << p.second << std::endl; 

            // mark current char is present in currentMap = map.at(i)
            map.at(i).insert(p);

            std::unordered_map<char, int> unorderedMap = map.at(i);
            std::map<char, int> orderedMap(unorderedMap.begin(), unorderedMap.end());
            for(auto it = orderedMap.begin(); it != orderedMap.end(); ++it)
                std::cout << it->second;
        }
    }



    for(auto it = ordered.begin(); it != ordered.end(); ++it)
        std::cout << it->second;



    // Display the content of map
    for (int i=0; i<map.size(); ++i)
    {
        std::unordered_map<char, int> currentMap = map.at(i);
        std::cout << "map[" << i << "] = " << std::endl;
        for(std::unordered_map<char, int>::iterator it=currentMap.begin(); it!=currentMap.end(); ++it)
        {
            std::cout << it->first << "=>" << it->second << std::endl;
        }
    }


    // declare the ans vector: vector of strings belong to the same anagrams
    std::vector<std::vector<std::string>> ans;
    //  vector indicating if the current string is already in one anagram group
    std::vector<bool> inAlready(strs.size(), false); 

    for(int i=0; i<map.size(); ++i)
    {
        for(int j=i+1; j<strs.size();++j)
        {
            // save matched string into the currentGroup
            if(map.at(i)==map.at(j))
            {
                // find the group in which strs(i) belongs to 
                std::string key = strs.at(i);
                // present is a boolean variable indicating if the current string(key) is present in any group
                bool present = false;
                for (int k=0; k<ans.size(); ++k)
                {
                    std::vector<std::string> existingGroup = ans.at(k);
                    std::vector<std::string>::iterator itr = std::find(existingGroup.begin(), existingGroup.end(), key);
                    if (itr != existingGroup.cend()) {
                    	std::cout << "Element present at index " << std::distance(existingGroup.begin(), itr);
                        // add the string at index j into the corresponding existing group in ans
                        ans.at(k).push_back(strs.at(j));
                        // remove the string from input list
                        inAlready.at(j) = true;
                        present = true;
                    }
                    else 
                    {
                    	std::cout << "Not present in the group[" << k << "]" << std::endl;
                    }
                }
                // key is not present in any group yet
                if(!present)
                {
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
        }  

    }


    return ans;
}

int main()
{
    std::string input[] = {"eat", "tea", "tan", "ate", "nat", "bat"};
    std::vector<std::string> inputVector;
    int n = sizeof(input)/sizeof(input[0]);
    for (int i=0; i<n; ++i)
    {
        inputVector.push_back(input[i]);
    }
    for (int i=0; i<inputVector.size(); ++i)
    {
        std::cout << "input[" << i << "] = " << inputVector.at(i) << std::endl;
    }
    std::vector<std::vector<std::string>> output = groupAnagrams(inputVector);
    for (int i=0; i<output.size(); ++i)
    {
        std::cout << "output[" << i << "] = " << std::endl;
        for (int j=0; j<output.at(i).size(); ++j)
        { 
            std::vector<std::string> curVect = output.at(i);
            std::cout << "[" << curVect.at(j) << "]" << std::endl;            
        }
    }
    return 0;
}


    //     // check if the string is already in a group
    //     if( !(inAlready.at(i)) )
    //     {
    //         // vector of strings storing the strings below to the same anagram group
    //         std::vector<std::string> currentGroup;

    //         // save the current string into the current group
    //         currentGroup.push_back(strs.at(i));
    //         for(int j=i+1; j<strs.size();++j)
    //         {
    //             // save matched string into the currentGroup
    //             if(map.at(i)==map.at(j))
    //             {
    //                 currentGroup.push_back(strs.at(j));
    //                 // remove the string from input list
    //                 inAlready.at(i) = true;
    //             }
    //         }  
    //         //Save the current group into the ans vector
    //         ans.push_back(currentGroup);          
    //     }

    //     int key = 6;

	// std::vector<int>::iterator itr = std::find(v.begin(), v.end(), key);

	// if (itr != v.cend()) {
	// 	std::cout << "Element present at index " << 
	// 				std::distance(v.begin(), itr);
	// }
	// else {
	// 	std::cout << "Element not found";
	// }
