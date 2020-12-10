class Solution {
public:
    vector<vector<int>> dp ;
    bool canPartition(vector<int>& nums) ;
    bool helper(vector<int>& nums , int ind , int set1 , int set2) ;
};

bool Solution :: helper(vector<int>& nums , int ind , int set1 , int set2)
{
    if(ind == nums.size() and set1 == set2) return dp[set1][set2] = 1 ;
    if(ind >= nums.size()) return dp[set1][set2] = 0 ;
    if(dp[set1][set2] != -1) return dp[set1][set2] ;
    return dp[set1][set2] = helper(nums , ind + 1 , set1 + nums[ind] , set2) or
            helper(nums , ind + 1 , set1 , set2 + nums[ind]) ;
}
bool Solution :: canPartition(vector<int>& nums)
{
    int sum = accumulate(begin(nums) , end(nums) , 0) ;
    dp.assign(sum + 1 , vector<int>(sum + 1 , -1)) ;
    return helper(nums , 0 , 0 , 0) ;
}
