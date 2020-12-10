class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) ;
};

int Solution :: minimumTotal(vector<vector<int>>& triangle)
{
    int n = triangle.size() ;
    vector<vector<int>> dp(n , vector<int>(n , -1)) ;
    for(int i = 0 ; i < n ; i++)
    {
        dp[n - 1][i] = triangle[n - 1][i] ;
    }
    
    for(int level = n - 2 ; level >= 0 ; level--)
    {
        for(int pos = 0 ; pos <= level ; pos++)
        {
            dp[level][pos] = min(dp[level + 1][pos] , dp[level + 1][pos + 1]) + triangle[level][pos] ;
        }
    }
    
    return dp[0][0] ;
}
