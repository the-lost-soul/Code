class Solution {
public:
    int numTrees(int n) ;
};

int Solution :: numTrees(int n)
{
    vector<int>dp(n + 1 , 0) ;
    dp[0] = 1 ;
    dp[1] = 1 ;
    for(int node = 2 ; node <= n ; node++)
    {
        for(int left = 1 ; left <= node ; left++)
        {
            dp[node] += dp[left - 1]*dp[node - left] ;
        }
    }
    return dp[n] ;
}
