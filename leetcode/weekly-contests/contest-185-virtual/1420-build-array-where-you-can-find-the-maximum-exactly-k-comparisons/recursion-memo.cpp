class Solution {
public:
    vector<vector<vector<int>>> dp ;
    const int mod = 1e9 + 7 ;
    int numOfArrays(int n, int m, int k) ;
    int helper(int prevMax , int n , int m , int k) ;
};

int Solution :: helper(int prevMax , int n , int m , int k)
{
    if(n == 0 and k == 0)return 1 ;
    if(n == 0)return 0 ;
    if(dp[n][prevMax][k] != -1)return dp[n][prevMax][k] ;
    int count = 0 ;
    for(int ele = 1 ; ele <= m ; ele++)
    {
        int cost = k ;
        int newMax = prevMax ;
        if(ele > newMax)
        {
            newMax = ele ;
            cost-- ;
        }
        if(cost < 0)break ;
        count = (count%mod + helper(newMax , n - 1 , m , cost)%mod)%mod ;
    }
    return dp[n][prevMax][k] = count ;
}
int Solution :: numOfArrays(int n , int m , int k)
{
    dp.resize(n + 1 , vector<vector<int>>(m + 1 , vector<int>(k + 1 , -1))) ;
    int prevMax = 0 ;
    return helper(prevMax , n , m , k) ;
}
