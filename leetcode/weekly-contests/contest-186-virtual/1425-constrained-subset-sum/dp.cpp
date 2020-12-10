class Solution {

public:
    int constrainedSubsetSum(vector<int>& nums, int k) ;
};

int Solution :: constrainedSubsetSum(vector<int>& nums , int k)
{
    vector<int>dp(nums.size() , 0) ;
    for(int i = 0 ; i < nums.size() ; i++)
    {
        dp[i] = nums[i] ;
        for(int j = i - 1 ; j >= max(0 , i - k) ; j--)
        {
            dp[i] = max(dp[i] , nums[i] + dp[j]) ;
        }
    }
    return *max_element(dp.begin() , dp.end()) ;
}
