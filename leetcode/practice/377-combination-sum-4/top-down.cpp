class Solution {
public:
    int combinationSum4(vector<int>& nums, int target) ;
};

int Solution :: combinationSum4(vector<int>& nums, int target)
{
    vector<unsigned int>dp(target + 1 , 0) ;
    dp[0] = 1 ;
    sort(begin(nums) , end(nums)) ;
    for(int sum = 1 ; sum <= target ; sum++)
    {
        for(auto ele : nums)
        {
            if(sum >= ele)
            {
                dp[sum] += dp[sum - ele] ;
            }
            else break ;
        }
    }
    return dp[target] ;
}
