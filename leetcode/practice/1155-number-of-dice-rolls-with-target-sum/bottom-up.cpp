class Solution {
    const int mod = 1e9 + 7 ;
public:
    int numRollsToTarget(int d, int f, int target) ;
};


int Solution :: numRollsToTarget(int dice , int f , int target)
{
    vector<vector<int>>dp(dice + 1 , vector<int>(target + 1 , 0)) ;
    dp[0][0] = 1 ;
    for(int d = 1 ; d <= dice ; d++)
    {
        for(int t = 1 ; t <= target ; t++)
        {
            for(int val = 1 ; val <= f and val <= t ; val++)
            {
                dp[d][t] = (dp[d][t] + dp[d - 1][t - val])%mod ;
            }
        }
    }
    return dp[dice][target] ;
}
