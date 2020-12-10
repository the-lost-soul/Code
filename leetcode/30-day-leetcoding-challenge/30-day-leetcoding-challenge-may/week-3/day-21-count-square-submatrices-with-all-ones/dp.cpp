class Solution {
public:
    int countSquares(vector<vector<int>>& matrix) ;
};

int Solution :: countSquares(vector<vector<int>>& matrix)
{
    int res = 0 ;
    for(int i = 0 ; i < matrix.size() ; i++)
    {
        for(int j = 0 ; j < matrix[0].size() ; j++)
        {
            if(matrix[i][j])
            {
                if(i == 0 or j == 0)
                {
                    res += 1 ;
                }
                else
                {
                    int cellVal = min(matrix[i - 1][j - 1] , min(matrix[i - 1][j] , matrix[i][j - 1])) ;
                    matrix[i][j] += cellVal ;
                    res += matrix[i][j] ;
                }
            }
        }
    }
    return res ;
}
