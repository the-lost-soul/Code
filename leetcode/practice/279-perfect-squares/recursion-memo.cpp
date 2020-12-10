class Solution {
public:
    vector<int>dp ;
    int numSquares(int n) ;
    int helper(int n) ;
};

int Solution :: helper(int n)
{
    if(n <= 0)return 0 ;
    if(dp[n] != INT_MAX)
        return dp[n] ;
    for(int i = 1 ; i*i <= n ; i++)
    {
        dp[n] = min(dp[n] , 1 + helper(n - i*i)) ;
    }
    return dp[n] ;
}

int Solution :: numSquares(int n)
{
    if(n == 0)return 0 ;
    dp.resize(n + 1 , INT_MAX) ;
    dp[0] = 0 ;
    for(int i = 1 ; i*i <= n ; i++)
    {
        dp[n] = min(dp[n] , 1 + helper(n - i*i)) ;
    }
    return dp[n] ;
}
