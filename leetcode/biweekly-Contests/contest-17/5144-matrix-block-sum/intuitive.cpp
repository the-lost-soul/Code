class Solution {
public:
    vector<vector<int>> matrixBlockSum(vector<vector<int>>& mat, int k) ;
};

vector<vector<int>> Solution :: matrixBlockSum(vector<vector<int>>& mat , int K)
{
    int row = mat.size() , col = mat[0].size() ;
    vector<vector<int>>prefixSum(row , vector<int>(col , 0)) ;
    int sum = 0 ;
    for(int i = 0 ; i < row ; i++)
    {
        sum = 0 ;
        for(int j = 0 ; j < col ; j++)
        {
            sum += mat[i][j] ;
            prefixSum[i][j] = sum ;
        }
    }
    
    vector<vector<int>>ans(row , vector<int>(col , 0)) ;
    for(int i = 0 ; i < row ; i++)
    {
        for(int j = 0 ; j < col ; j++)
        {
            int rUpper = min(row - 1 , i + K) , rLower = max(0 , i - K) ;
            int cUpper = min(col - 1 , j + K) , cLower = max(0 , j - K) ;
            for(int k = rLower ; k <= rUpper ; k++)
            {
                ans[i][j] += prefixSum[k][cUpper] - prefixSum[k][cLower] + mat[k][cLower] ;
            }
            
        }
    }
    return ans ;
}
