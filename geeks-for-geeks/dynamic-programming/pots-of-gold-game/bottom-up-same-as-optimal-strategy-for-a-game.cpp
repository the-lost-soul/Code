int maxCoins(int arr[] , int size)
{
    vector<vector<int>>dp(size , vector<int>(size , 0)) ;
    for(int i = 0 ; i < size ; i++)dp[i][i] = arr[i] ;
    for(int gap = 2 ; gap <= size ; gap++)
    {
        for(int i = 0 ; i <= size - gap ; i++)
        {
            int j = i + gap - 1 ;
            
            int strategy1 = i + 2 <= j ? dp[i + 2][j] : 0 ;
            int strategy2 = i + 1 <= j - 1 ? dp[i + 1][j - 1] : 0 ;
            int strategy3 = i <= j - 2 ? dp[i][j - 2] : 0 ;
            dp[i][j] = max(arr[i] + min(strategy1 , strategy2) , arr[j] + min(strategy2 , strategy3)) ;
        }
    }
    return dp[0][size - 1] ;
}
