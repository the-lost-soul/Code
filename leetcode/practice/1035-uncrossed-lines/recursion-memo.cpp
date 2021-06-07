class Solution
{
    vector<vector<int>>dp ;
    public :
        int maxUncrossedLines(vector<int>& arr1 , vector<int>& arr2) ;
        int helper(vector<int>& arr1 , vector<int>& arr2 , int i , int j) ;
} ;

int Solution :: helper(vector<int>& arr1 , vector<int>& arr2 , int i , int j)
{
    int size1 = arr1.size() , size2 = arr2.size() ;
    if(i >= size1 or j >= size2) return 0 ;
    if(dp[i][j] != -1) return dp[i][j] ;
    if(arr1[i] == arr2[j])
    {
        return dp[i][j] = 1 + helper(arr1 , arr2 , i + 1 , j + 1) ;
    }
    return dp[i][j] = max(helper(arr1 , arr2 , i , j + 1) , helper(arr1 , arr2 , i + 1 , j)) ;
}


int Solution :: maxUncrossedLines(vector<int>& arr1 , vector<int>& arr2)
{
    dp.assign(arr1.size() , vector<int>(arr2.size() , -1)) ;
    return helper(arr1 , arr2 , 0 , 0) ;
}
