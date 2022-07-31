class Solution 
{
    const int mod = 1e9 + 7 ;
    vector<vector<vector<int>>>dp ;
    vector<vector<int>>preSum ;
public:
    int ways(vector<string>& pizza, int k) ;
    int helper(int currR , int currC , int cut , int row , int col) ;
};

int Solution :: helper(int currR , int currC , int cut , int row , int col)
{
    if(preSum[currR][currC] == 0)return 0 ;
    if(cut == 0)return 1 ;
    if(dp[currR][currC][cut] != -1)return dp[currR][currC][cut] ;
    int ans = 0 ;
    for(int i = currR ; i < row ; i++)
    {
        if(preSum[currR][currC] - preSum[i][currC] > 0)
        {
            ans += helper(i , currC , cut - 1 , row , col) ;
            ans = ans%mod ;
        }
    }
    
    for(int j = currC ; j < col ; j++)
    {
        if(preSum[currR][currC] - preSum[currR][j] > 0)
        {
            ans += helper(currR , j , cut - 1 , row , col) ;
            ans = ans%mod ;
        }
    }
    
    return dp[currR][currC][cut] = ans ;
}
int Solution :: ways(vector<string>& pizza , int k)
{
    int row = pizza.size() , col = pizza[0].size() ;
    preSum.resize(row + 1 , vector<int>(col + 1 , 0)) ;
    for(int i = row - 1 ; i >= 0 ; i--)
    {
        for(int j = col - 1 ; j >= 0 ; j--)
        {
            preSum[i][j] = preSum[i + 1][j] + preSum[i][j + 1] - preSum[i + 1][j + 1] + (pizza[i][j] == 'A') ;
        }
    }
    
    dp.resize(row , vector<vector<int>>(col , vector<int>(k , -1))) ;
    return helper(0 , 0 , k - 1 , row , col) ;
}
