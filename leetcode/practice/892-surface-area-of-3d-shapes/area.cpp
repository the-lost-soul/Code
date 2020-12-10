class Solution {
public:
    int surfaceArea(vector<vector<int>>& grid) ;
    bool validMove(int currRow , int currCol , int row , int col) ;
};

bool Solution :: validMove(int currRow , int currCol , int row , int col)
{
    return currRow >= 0 and currRow < row and currCol >= 0 and currCol < col ;
}
int Solution :: surfaceArea(vector<vector<int>>& grid)
{
    int area = 0 , row , col ;
    row = col = grid.size() ;
    for(int i = 0 ; i < row ; i++)
    {
        for(int j = 0 ; j < col ; j++)
        {
            if(grid[i][j])
                area += 2 ;
            if(validMove(i + 1 , j , row , col))
            {
                area += max(grid[i][j] - grid[i + 1][j] , 0) ;
            }
            else
                area += grid[i][j] ;
            
            if(validMove(i - 1 , j, row , col))
            {
                area += max(grid[i][j] - grid[i - 1][j] , 0) ;
            }
            else
                area += grid[i][j] ;
            
            if(validMove(i , j + 1 , row , col))
            {
                area += max(grid[i][j] - grid[i][j + 1] , 0) ;
            }
            else
                area += grid[i][j] ;
            
            if(validMove(i , j - 1 , row , col))
            {
                area += max(grid[i][j] - grid[i][j - 1] , 0) ;
            }
            else
                area += grid[i][j] ;
        }
    }
    return area ;
}
