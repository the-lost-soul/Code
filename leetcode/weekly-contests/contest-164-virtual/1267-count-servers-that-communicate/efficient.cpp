class Solution {
public:
    int countServers(vector<vector<int>>& grid) ;
};


int Solution :: countServers(vector<vector<int>>& grid)
{
    int row = grid.size() , col = grid[0].size() ;
    vector<int>rowServer(row , 0) , colServer(col , 0) ;
    for(int i = 0 ; i < row ; i++)
    {
        for(int j = 0 ; j < col ; j++)
        {
            if(grid[i][j] == 1)
            {
                rowServer[i]++ ;
                colServer[j]++ ;
                
            }
        }
    }
    int ans = 0 ;
    for(int i = 0 ; i < row ; i++)
    {
        for(int j = 0 ; j < col ; j++)
        {
            if((grid[i][j] == 1) and (rowServer[i] > 1 or colServer[j] > 1))
                ans++ ;
        }
    }
    
    return ans ;
}
