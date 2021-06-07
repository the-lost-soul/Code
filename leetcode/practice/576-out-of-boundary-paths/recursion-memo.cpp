class Solution {
public:
    const int mod = 1e9 + 7 ;
    vector<vector<vector<int>>>dp ;
    int findPaths(int m, int n, int N, int i, int j) ;
    int helper(int m , int n , int N , int i , int j) ;
};

int Solution :: helper(int m , int n , int N , int i , int j)
{
    if(i < 0 or j < 0 or i >= m or j >= n)
        return 1 ;
    
    if(N == 0)
        return 0 ;
    if(dp[i][j][N] != -1)
        return dp[i][j][N] ;
    int left = helper(m , n , N - 1 , i , j - 1)%mod ;
    int right = helper(m , n , N - 1 , i , j + 1)%mod ;
    int down = helper(m , n , N - 1 , i + 1 , j)%mod ;
    int up = helper(m , n , N - 1 , i - 1 , j)%mod ;
    return dp[i][j][N] = ((left + right)%mod + (up + down)%mod)%mod ;
}

int Solution :: findPaths(int m , int n,  int N , int i , int j)
{
    dp.resize(m , vector<vector<int>>(n , vector<int>(N + 1 , -1))) ;
    return helper(m , n , N , i , j) ;
}
