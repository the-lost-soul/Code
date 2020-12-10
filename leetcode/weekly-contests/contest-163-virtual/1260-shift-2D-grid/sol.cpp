class Solution {
public:
    vector<vector<int>> shiftGrid(vector<vector<int>>& grid, int k) ;
};

vector<vector<int>> Solution :: shiftGrid(vector<vector<int>>& grid , int k)
{
    int row = grid.size() , col = grid[0].size() ;
    vector<vector<int>>ans(grid) ;
    while(k--)
    {
        int ele = ans[row - 1][col - 1] ;
        for(int i = 0 ; i < row ; i++)
        {
            for(int j = 0 ; j < col ; j++)
            {
                swap(ele , ans[i][j]) ;
            }
        }
    }
    return ans ;
}
