class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& arr) ;
};

int** createMatrix(int** dp , int size)
{
    dp = new int*[size] ;
    for(int i = 0 ; i < size ; i++)
    {
        dp[i] = new int[size] ;
    }
    return dp ;
}
void fillMatrix(int** dp , int size)
{
    for(int i = 0 ; i < size ; i++)
        for(int j = 0 ; j < size ; j++)
            dp[i][j] = INT_MAX ;
}
void printMatrix(int** dp , int size)
{
    for(int i = 0 ; i < size ; i++)
    {
        for(int j = 0 ; j < size ; j++)
            cout << dp[i][j] << " " ;
        cout << endl ;
    }
}
int helper(vector<vector<int>>& arr , int** dp , int currRow , int start , int end)
{
    // If currRow is invalid .
    if(currRow >= arr.size())return 0 ;
    // If col from where to start is invalid , then start from col 0
    if(start < 0)start = 0 ;
    // If column till where we can iterate , then iterate till last column .
    if(end >= arr.size())end = arr.size() - 1 ;
    
    int minSum = INT_MAX ;
    for(int i = start ; i <= end ; i++)
    {
        
        // If the current cell is still not visited , then visit it and
        // recur for next row
        if(dp[currRow][i] == INT_MAX)
            dp[currRow][i] = min(dp[currRow][i] , arr[currRow][i]
                                + helper(arr , dp , currRow + 1 , i - 1 , i + 1)) ;
        // Get the minimum from current row .
        minSum = min(minSum , dp[currRow][i]) ;
    }
    
    return minSum ;
}
int Solution :: minFallingPathSum(vector<vector<int>>& arr)
{
    int col = arr.size() ;
    
    int** dp = createMatrix(dp , col) ;
    fillMatrix(dp , col) ;
    // printMatrix(dp , col) ;
    int sum = INT_MAX ;
    // Starting from first row , get the minimum path sum for each column .
    for(int i = 0 ; i < col ; i++)
    {
        sum = min(sum , arr[0][i] + helper(arr, dp , 1 , i - 1 , i + 1)) ;
    }
    
    return sum ;
    
    
}
