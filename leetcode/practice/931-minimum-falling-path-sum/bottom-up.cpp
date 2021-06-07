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
void fillMatrix(vector<vector<int>>& arr , int** dp , int size)
{
    for(int i = 0 ; i < size ; i++)
    {
        for(int j = 0 ; j < size ; j++)
        {
            if(i == size - 1)dp[i][j] = arr[i][j] ;
            else dp[i][j] = INT_MAX ;
        }
    }
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

int Solution :: minFallingPathSum(vector<vector<int>>& arr)
{
    int col = arr.size() ;
    
    int** dp = createMatrix(dp , col) ;
    fillMatrix(arr , dp , col) ;
    // printMatrix(dp , col) ;
    int sum = INT_MAX ;
    // Bottom up approach .
    for(int i = col - 2 ; i >= 0 ; i--)
    {
        for(int j = 0 ; j < col ; j++)
        {
            int minEle = INT_MAX ;
            // Find the minimum element from the (i + 1)th row 
            minEle = min(minEle , dp[i + 1][j]) ;
            minEle = min(minEle , dp[i + 1][j - 1 >= 0 ? j - 1 : 0]) ;
            minEle = min(minEle , dp[i + 1][j + 1 >= col ? col - 1 : j + 1]) ;
            dp[i][j] = arr[i][j] + minEle ;
        }
    }
    for(int i = 0 ; i < col ; i++)
    {
        sum = min(sum , dp[0][i]) ;
    }
    return sum ;
    
    
}
