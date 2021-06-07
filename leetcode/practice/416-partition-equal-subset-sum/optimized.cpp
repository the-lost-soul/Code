class Solution {
public:
    vector<vector<int>> dp ;
    int sum ;
    bool canPartition(vector<int>& nums) ;
    bool helper(vector<int>& nums , int ind , int set1 , int set2) ;
};

bool Solution :: helper(vector<int>& nums , int ind , int set1 , int set2)
{
    if(set1 > sum or set2 > sum) return 0 ;
    if(ind == nums.size() and set1 == set2) return 1 ;
    if(ind >= nums.size()) return 0 ;
    if(dp[set1][set2] != -1) return dp[set1][set2] ;
    return dp[set1][set2] = helper(nums , ind + 1 , set1 + nums[ind] , set2) or
            helper(nums , ind + 1 , set1 , set2 + nums[ind]) ;
}
bool Solution :: canPartition(vector<int>& nums)
{
    sum = accumulate(begin(nums) , end(nums) , 0) ;
    if(sum%2)return false ;
    sum /= 2 ;
    dp.assign(sum + 1 , vector<int>(sum + 1 , -1)) ;
    return helper(nums , 0 , 0 , 0) ;
}
