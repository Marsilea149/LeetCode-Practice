#include <iostream>
#include <vector>

using namespace std;
vector<int> decompressRLElist(vector<int>& nums);


vector<int> decompressRLElist(vector<int>& nums) {
    //Initiate the output vector
    vector<int> ans;
    
    for(int i=0; i<nums.size(); i+=2) //loop through the inout array
    {
        for(int j=0; j<nums[i]; j++) //loop through the size of each sub-vector
        {
            ans.push_back(nums[i+1]); 
        }
    }
    return ans;
}


int main()
{
    vector<int> input;
    input.push_back(1);
    input.push_back(2);
    input.push_back(3);
    input.push_back(4);    
    vector<int> res;
    res = decompressRLElist(input);
    for(int i = 0; i < res.size(); i++){
        cout << "res["<<i<<"]=" << res[i]<<endl;
    }

    return 0;

}
