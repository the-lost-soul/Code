class Solution {
public:
    bool canPartition(vector<int>& nums) ;
    bool helper(vector<int>& nums , int ind , int set1 , int set2) ;
};

bool Solution :: helper(vector<int>& nums , int ind , int set1 , int set2)
{
    if(ind == nums.size() and set1 == set2) return true ;
    if(ind >= nums.size()) return false ;
    return helper(nums , ind + 1 , set1 + nums[ind] , set2) or
            helper(nums , ind + 1 , set1 , set2 + nums[ind]) ;
}
bool Solution :: canPartition(vector<int>& nums)
{
    return helper(nums , 0 , 0 , 0) ;
}
