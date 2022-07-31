class Solution
{
  public:
    long long int nthFibonacci(long long int n)
    {
        vector<int>dp(n + 1 , 0) ;
        dp[0] = 0 ;
        dp[1] = 1 ;
        dp[2] = 1 ;

        for(int i = 3 ; i <= n ; i++)
            dp[i] = (dp[i - 1] + dp[i - 2])%(1000000007) ;
        return dp[n] ;
    }
};
