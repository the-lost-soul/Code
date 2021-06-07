class Solution {
public:
    int maxIncreaseKeepingSkyline(vector<vector<int>>& grid) ;
};

int Solution :: maxIncreaseKeepingSkyline(vector<vector<int>>& grid)
{
    int row = grid.size() , col = grid[0].size() ;
    vector<int>vertical(col , INT_MIN) , horizontal(row , INT_MIN) ;
    for(int i = 0 ; i < row ; i++)
    {
        for(int j = 0 ; j < col ; j++)
        {
            vertical[j] = max(vertical[j] , grid[i][j]) ;
            horizontal[i] = max(horizontal[i] , grid[i][j]) ;
        }
    }
    int ans = 0 ;
    for(int i = 0 ; i < row ; i++)
    {
        for(int j = 0 ; j < col ; j++)
        {
            int temp = grid[i][j] ;
            grid[i][j] = min(horizontal[i] , vertical[j]) ;
            ans += (grid[i][j] - temp) ;
        }
    }
    return ans ;
}
