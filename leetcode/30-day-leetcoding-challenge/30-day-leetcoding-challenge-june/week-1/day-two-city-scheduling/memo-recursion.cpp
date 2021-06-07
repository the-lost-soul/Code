class Solution {
    int ans = INT_MAX ;
    vector<vector<int>>dp ;
public:
    int twoCitySchedCost(vector<vector<int>>& costs) ;
    int helper(vector<vector<int>>& costs , int a , int b) ;
};

int Solution :: helper(vector<vector<int>>& costs , int a , int b)
{
    if(a == costs.size()/2 and b == costs.size()/2)
    {
        dp[a][b] = 0 ;
        return 0 ;
    }
    
    if(dp[a][b] != INT_MAX)return dp[a][b] ;
    if(a < costs.size()/2)
        dp[a][b] = min(dp[a][b] , costs[a + b][0] + helper(costs , a + 1 , b)) ;
    if(b < costs.size()/2)
       dp[a][b] = min(dp[a][b] , costs[a + b][1] + helper(costs , a , b + 1)) ;
    return dp[a][b] ;
}
int Solution :: twoCitySchedCost(vector<vector<int>>& costs)
{
    dp.resize(costs.size()/2 + 1 , vector<int>(costs.size()/2 + 1 , INT_MAX)) ;
    int a = 0 , b = 0 ;
    dp[0][0] = helper(costs , a , b) ;
    return dp[0][0] ;
}
