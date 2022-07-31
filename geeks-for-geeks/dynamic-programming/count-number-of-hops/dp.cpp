class Solution
{
    public:
    //Function to count the number of ways in which frog can reach the top.
    long long countWays(int n)
    {
        long long mod = 1e9 + 7 ;
        if(n == 1)
            return 1 ;
        if(n == 2)
            return 2 ;
        if(n == 3)
            return 4 ;
        vector<long long>dp(n + 1 , 0) ;
        dp[1] = 1 ;
        dp[2] = 2 ;
        dp[3] = 4 ;
        for(int i = 4 ; i <=n ; i++)
        {
            dp[i] = (dp[i - 1] + dp[i - 2] + dp[i - 3])%mod ;
        }
        return dp[n] ;
    }
};
