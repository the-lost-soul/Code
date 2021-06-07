class Solution 
{
    int sum = 0 ;
    public:
        int maxSumDivThree(vector<int>& nums) ;
};


int Solution :: maxSumDivThree(vector<int>& nums)
{
    int len = nums.size() ;
    vector<int>dp(3 , 0) , prevDp(3);
    for(int i = 0 ; i < len ; i++)
    {
        prevDp = dp ;
        for(int j = 0 ; j < 3 ; j++)
        {
            int sum = nums[i] + prevDp[j] ;
            int k = sum%3 ;
            dp[k] = max(dp[k] , sum) ;
        }
    }
    return dp[0] ;
}
