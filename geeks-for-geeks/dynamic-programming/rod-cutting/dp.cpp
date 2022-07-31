class Solution
{
  public:
    int cutRod(int price[], int n)
    {
        vector<int>dp(n + 1 , INT_MIN) ;
        dp[0] = 0 ;

        for(int len = 1 ; len <= n ; len++)
        {
            for(int j = 0 ; j < len ; j++)
            {
                dp[len] = max(dp[len] , price[j] + dp[len - j - 1]) ;
            }
        }
        return dp[n] ;
    }
};
