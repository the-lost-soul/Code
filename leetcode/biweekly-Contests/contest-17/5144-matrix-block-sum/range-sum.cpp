class Solution {
public:
    vector<vector<int>>prefixSum ;
    vector<vector<int>> matrixBlockSum(vector<vector<int>>& mat, int k) ;
    int getSum(int rUpper , int rLower , int cUpper , int cLower) ;
}; 
int Solution :: getSum(int rUpper , int rLower , int cUpper , int cLower) 
{
    int topLeft = rLower != 0 and cLower != 0 ? prefixSum[rLower - 1][cLower - 1] : 0 ;
    int topRight = rLower != 0 ? prefixSum[rLower - 1][cUpper] : 0 ;
    int bottomLeft = cLower != 0 ? prefixSum[rUpper][cLower - 1] : 0 ;
    int bottomRight = prefixSum[rUpper][cUpper] ;
    int sum = bottomRight - topRight ;
    sum -= (bottomLeft - topLeft) ;
    return sum ;
}
vector<vector<int>> Solution :: matrixBlockSum(vector<vector<int>>& mat , int K)
{
    int row = mat.size() , col = mat[0].size() ;
    prefixSum.resize(row) ;
    for(int i = 0 ; i < row ; i++)
        prefixSum[i].resize(col) ;
    int sum = 0 ;
    for(int i = 0 ; i < row ; i++)
    {
        sum = 0 ;
        for(int j = 0 ; j < col ; j++)
        {
            sum += mat[i][j] ;
            prefixSum[i][j] = sum + (i != 0 ? prefixSum[i - 1][j] : 0) ;
        }
    }
    
    vector<vector<int>>ans(row , vector<int>(col , 0)) ;
    for(int i = 0 ; i < row ; i++)
    {
        for(int j = 0 ; j < col ; j++)
        {
            int rUpperLim = min(row - 1 , i + K) , rLowerLim = max(0 , i - K) ;
            int cUpperLim = min(col - 1 , j + K) , cLowerLim = max(0 , j - K) ;
            ans[i][j] = getSum(rUpperLim , rLowerLim , cUpperLim , cLowerLim) ;
            
        }
    }
    return ans ;
}
