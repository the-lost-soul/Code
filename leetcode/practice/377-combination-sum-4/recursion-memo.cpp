class Solution {
public:
    int combinationSum4(vector<int>& nums, int target) ;
    int helper(vector<int>& nums , vector<int>& dp , int target) ;
};

int Solution :: helper(vector<int>& nums , vector<int>& dp , int target)
{
    if(dp[target] != -1)
        return dp[target] ;
    int res = 0 ;
    for(int i = 0 ; i < size(nums) ; i++)
    {
        if(nums[i] <= target)
        {
            res += helper(nums , dp , target - nums[i]) ;
        }
    }
    return dp[target] = res ;
}

int Solution :: combinationSum4(vector<int>& nums, int target)
{
    vector<int>dp(target + 1 , -1) ;
    dp[0] = 1 ;
    helper(nums , dp , target) ;
    return dp[target] ;
}
