class Solution {
public:
    vector<vector<int>> shiftGrid(vector<vector<int>>& grid, int k) ;
};

vector<vector<int>> Solution :: shiftGrid(vector<vector<int>>& grid , int k)
{
    int row = grid.size() , col = grid[0].size() ;
    vector<vector<int>>ans(row , vector<int>(col , 0)) ;
    k %= row*col ;
    for(int i = 0 ; i < row ; i++)
    {
        for(int j = 0 ; j < col ; j++)
        {
            int relativePos = (i*col + j + k)%(row*col) , newRow = relativePos/col , newCol = (relativePos)%col ;
            ans[newRow][newCol] = grid[i][j] ;
        }
    }
    return ans ;
}
