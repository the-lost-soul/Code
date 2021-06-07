class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) ;
};

vector<int> Solution :: intersect(vector<int>& arr1 , vector<int>& arr2)
{
    unordered_map<int , int>hash ;
    for(auto ele : arr1)
        hash[ele]++ ;
    
    vector<int>ans ;
    for(auto ele : arr2)
    {
        if(hash[ele] > 0)
        {
            ans.push_back(ele) ;
            hash[ele]-- ;
        }
    }
    return ans ;
}
