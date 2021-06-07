class Solution {
public:
    int countSquares(vector<vector<int>>& matrix) ;
};

int Solution :: countSquares(vector<vector<int>>& matrix)
{
    int row = matrix.size() , col = matrix[0].size() ;
    int dp[row + 1][col + 1] ;
    memset(dp , 0 , sizeof(dp)) ;
    int ans = 0 ;
    for(int i = 1 ; i <= row ; i++)
    {
        for(int j = 1 ; j <= col ; j++)
        {
            if(matrix[i - 1][j - 1] == 1)
            {
                dp[i][j] += min(dp[i - 1][j - 1] , min(dp[i - 1][j] ,  dp[i][j - 1])) + 1 ;
            }
            ans += dp[i][j] ;
        }
    }
    
    return ans ;
}
