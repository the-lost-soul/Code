class Solution {
public:
    const int mod = 1e9 + 7 ;
    vector<vector<vector<vector<int>>>>dp ;
    int numOfWays(int n) ;
    int helper(int n , int tile1 , int tile2 , int tile3) ;
};

int Solution :: helper(int n , int tile1 , int tile2 , int tile3)
{
    if(n == 0) return 1 ;
    if(dp[tile1][tile2][tile3][n] != -1) return dp[tile1][tile2][tile3][n] ;
    int colors[3] = {1 , 2 , 3} ;
    long res = 0 ;
    for(auto color1 : colors)
    {
        if(color1 != tile1)
        {
            for(auto color2 : colors)
            {
                if(color2 != tile2 and color1 != color2)
                {
                    for(auto color3 : colors)
                    {
                        if(color3 != tile3 and color3 != color2)
                        {
                            res = (res + helper(n - 1 , color1 , color2 , color3))%mod ;
                            
                        }
                    }
                }
            }
        }
    }
    return dp[tile1][tile2][tile3][n] = res ;
}

int Solution :: numOfWays(int n)
{
    dp.resize(4 , vector<vector<vector<int>>>(4 , vector<vector<int>>(4 , vector<int>(n + 1 , -1)))) ;
    return helper(n , 0 , 0 , 0) ;
}
