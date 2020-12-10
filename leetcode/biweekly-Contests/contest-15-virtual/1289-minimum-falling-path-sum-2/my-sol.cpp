class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& arr) ;
};

int Solution :: minFallingPathSum(vector<vector<int>>& arr)
{
    int row = arr.size() , col = arr[0].size() ;
    vector<vector<int>>dp(row , vector<int>(col , 70000)) ;
    // First row .
    for(int c = 0 ; c < col ; c++)
    {
        dp[0][c] = arr[0][c] ;
    }
    int ans = INT_MAX ;
    for(int i = 1 ; i < row ; i++)
    {
        for(int j = 0 ; j < col ; j++)
        {
            for(int k = 0 ; k < col ; k++)
                if(k != j)
                    dp[i][j] = min(dp[i][j] , arr[i][j] + dp[i - 1][k]) ;
            if(i == row - 1)
                ans = min(ans , dp[i][j]) ;
        }
        
    }
    
    return ans ;
    
}
