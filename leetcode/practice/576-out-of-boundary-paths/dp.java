class Solution
{
    int[][][] dp ;
    int mod = 1000000007 ;
    public int solve(int m , int n , int maxMove , int r , int c)
    {
        if(r < 0 || r >= m || c < 0 || c >= n)
            return 1 ;
        if(maxMove <= 0)
            return 0 ;

        if(dp[r][c][maxMove] != -1)
            return dp[r][c][maxMove] ;
        int left = solve(m , n , maxMove - 1 , r , c - 1)%mod ;
        int right = solve(m , n , maxMove - 1 , r , c + 1)%mod ;
        int up = solve(m , n , maxMove - 1 , r - 1 , c)%mod ;
        int down = solve(m , n , maxMove - 1 , r + 1 , c)%mod ;
        dp[r][c][maxMove] = ((left + right)%mod + (up + down)%mod)%mod ; 
        return dp[r][c][maxMove] ;
    }

    public int findPaths(int m, int n, int maxMove, int startRow, int startColumn)
    {
        dp = new int[m][n][maxMove + 1] ;
        for(int i = 0 ; i < m ; i++)
            for(int j = 0 ; j < n ; j++)
                for(int k = 0 ; k <= maxMove ; k++)
                    dp[i][j][k] = -1 ;

        return solve(m , n , maxMove , startRow , startColumn) ;
    }
}
