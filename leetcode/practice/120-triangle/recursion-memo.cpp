class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) ;
    int helper(vector<vector<int>>& triangle , vector<vector<int>>& dp , int level , int pos) ;
};

int Solution :: helper(vector<vector<int>>& triangle , vector<vector<int>>& dp , int level , int pos)
{
    if(level + 1 >= triangle.size())
        return triangle[level][pos] ;
    
    if(dp[level][pos] != -1)
        return dp[level][pos] ;
    dp[level][pos] = triangle[level][pos] + min(helper(triangle , dp , level + 1 , pos) , 
                                    helper(triangle , dp , level + 1 , pos + 1)) ;
    
    return dp[level][pos] ;
}
int Solution :: minimumTotal(vector<vector<int>>& triangle)
{
    vector<vector<int>> dp(triangle.size() , vector<int>(triangle.size() , -1)) ;
    dp[0][0] = helper(triangle , dp , 0 , 0) ;
    return dp[0][0] ;
}
