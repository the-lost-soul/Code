class Solution 
{
    bool boundary = false ;
    int row , col ;
    public:
        int closedIsland(vector<vector<int>>& grid) ;
        void dfs(vector<vector<int>>& grid , vector<vector<int>>& visited , int i , int j) ;
};

void Solution :: dfs(vector<vector<int>>& grid , vector<vector<int>>& visited , int i , int j)
{
    
    if(i < 0 or j < 0 or i >= row or j >= col)
    {
        boundary = true ;
        return ;
    }
    if(grid[i][j] == 1 or visited[i][j] == 1)return ;
    visited[i][j] = 1 ;
    dfs(grid , visited , i + 1 , j) ;
    dfs(grid , visited , i - 1 , j) ;
    dfs(grid , visited , i , j + 1) ;
    dfs(grid , visited , i , j - 1) ;
}
int Solution :: closedIsland(vector<vector<int>>& grid)
{
    row = grid.size() , col = grid[0].size() ;
    vector<vector<int>>visited(row , vector<int>(col , 0)) ;
    int ans = 0 ;
    for(int i = 0 ; i < row ; i++)
    {
        for(int j = 0 ; j < col ; j++)
        {
            if(visited[i][j] == 0 and grid[i][j] == 0)
            {
                boundary = false ;
                dfs(grid , visited , i , j) ;
                if(!boundary)
                    ans++ ;
            }
        }
    }
    return ans ;
}
