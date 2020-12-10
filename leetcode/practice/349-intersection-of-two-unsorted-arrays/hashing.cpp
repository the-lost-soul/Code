class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) ;
};

vector<int> Solution :: intersection(vector<int>& arr1 , vector<int>& arr2)
{
    unordered_map<int , int>hash ;
    for(auto ele : arr1)
    {
        // We only want want copy of each element to be hashed
        // and hence the equality is with zero
        if(hash[ele] == 0)
            hash[ele]++;

    }
    vector<int>ans ;
    for(auto ele : arr2)
    {
        if(hash[ele] == 1)
        {
            hash[ele]-- ;
            ans.push_back(ele) ;
        }
    }
    return ans ;
}
