class Solution 
{
    int sum = 0 ;
    public:
        int maxSumDivThree(vector<int>& nums) ;
};


int Solution :: maxSumDivThree(vector<int>& nums)
{
    int len = nums.size() ;
    vector<vector<int>>dp(len + 1 , vector<int>(3 , 0)) ;
    for(int i = 1 ; i <= len ; i++)
    {
        int num = nums[i - 1] ;
        for(int j = 0 ; j < 3 ; j++)
        {
            dp[i][j] = max(dp[i][j] , dp[i - 1][j]) ;
            int sum = num + dp[i - 1][j] ;
            int k = sum%3 ;
            dp[i][k] = max(dp[i][k] , sum) ;
        }
    }
    return dp[len][0] ;
}
