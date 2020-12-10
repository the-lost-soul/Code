const int mod = 1e9 + 7 ;
int fun(string& str)
{
    int n = str.size() ;
    vector<vector<long>>dp(n + 1 , vector<long>(3 , 0)) ;
    for(int i = 1 ; i <= n ; i++)
    {
        if(str[i - 1] == 'a')
        {
            dp[i][0] = 1 + (2*dp[i - 1][0])%mod ;
            dp[i][1] = dp[i - 1][1] ;
            dp[i][2] = dp[i - 1][2] ;
        }
        else if(str[i - 1] == 'b')
        {
            dp[i][1] = ((2*dp[i - 1][1])%mod + dp[i - 1][0])%mod ;
            dp[i][0] = dp[i - 1][0] ;
            dp[i][2] = dp[i - 1][2] ;
        }
        else if(str[i - 1] == 'c')
        {
            dp[i][2] = ((2*dp[i - 1][2])%mod + dp[i - 1][1])%mod ;
            dp[i][0] = dp[i - 1][0] ;
            dp[i][1] = dp[i - 1][1] ;
        }
    }
    return dp[n][2]%mod ;
}
