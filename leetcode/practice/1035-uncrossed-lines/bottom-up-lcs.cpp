class Solution
{
    public :
        int maxUncrossedLines(vector<int>& arr1 , vector<int>& arr2) ;
} ;

int Solution :: maxUncrossedLines(vector<int>& arr1 , vector<int>& arr2)
{
    int size1 = arr1.size() , size2 = arr2.size() ;
    vector<vector<int>>dp(size1 + 1 , vector<int>(size2 + 1 , 0)) ;
    for(int i = 1 ; i <= size1 ; i++)
    {
        for(int j = 1 ; j <= size2 ; j++)
        {
            if(arr1[i - 1] == arr2[j - 1])
                dp[i][j] = 1 + dp[i- 1][j - 1] ;
            else
                dp[i][j] = max(dp[i][j - 1] , dp[i - 1][j]) ;
        }
    }
    return dp[size1][size2] ;
}
