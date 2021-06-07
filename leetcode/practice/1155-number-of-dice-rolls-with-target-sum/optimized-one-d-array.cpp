class Solution {
    const int mod = 1e9 + 7 ;
public:
    int numRollsToTarget(int d, int f, int target) ;
};


int Solution :: numRollsToTarget(int dice , int f , int target)
{
    vector<int>dp(target + 1 , 0) ;
    dp[0]= 1 ;
    for(int d = 1 ; d <= dice ; d++)
    {
        vector<int>temp(target + 1 , 0) ;
        for(int t = 1 ; t <= target ; t++)
        {
            for(int val = 1 ; val <= f and val <= t ; val++)
            {
                temp[t] = (temp[t] + dp[t - val])%mod ;
            }
        }
        dp = temp ;
    }
    return dp[target] ;
}
