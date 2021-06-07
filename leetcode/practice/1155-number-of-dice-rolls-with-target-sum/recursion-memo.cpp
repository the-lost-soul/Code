class Solution {
    const int mod = 1e9 + 7 ;
public:
    int numRollsToTarget(int d, int f, int target) ;
    int helper(vector<vector<int>>& dp , int d , int f , int target) ;
};

int Solution :: helper(vector<vector<int>>& dp , int d , int f , int target)
{
    if(target == 0 and d == 0)
        return 1 ;
    if(target <= 0 or d == 0)
        return 0 ;
    if(dp[d][target] != -1)
        return dp[d][target] ;
    int count = 0 ;
    for(int val = 1 ; val <= f ; val++)
    {
        count = (count + helper(dp , d - 1 , f , target - val))%mod ;
    }
    return dp[d][target] = count%mod ;
}

int Solution :: numRollsToTarget(int d , int f , int target)
{
    vector<vector<int>>dp(d + 1 , vector<int>(target + 1 , -1)) ;
    dp[d][target] = helper(dp , d , f , target) ;
    return dp[d][target] ;
}
