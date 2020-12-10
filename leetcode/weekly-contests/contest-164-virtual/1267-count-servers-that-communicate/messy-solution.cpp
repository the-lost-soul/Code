class Solution {
public:
    int countServers(vector<vector<int>>& grid) ;
    int dfs(vector<vector<int>>&grid , int sRow , int SCol , vector<vector<int>>& visited) ;
};

int Solution :: dfs(vector<vector<int>>& grid , int sRow , int sCol , vector<vector<int>>& visited)
{
    int row = grid.size() , col = grid[0].size() ;
    stack<int>myStack ;
    // Search on the row .
    for(int j = 0 ; j < col ; j++)
    {
        if(grid[sRow][j] == 1)
        {
            myStack.push(visited[sRow][j]) ;
            visited[sRow][j] = 1 ;
        }
    }
    
    // Search on the column .
    for(int i = 0 ; i < row ; i++)
    {
        if(grid[i][sCol] == 1 and visited[i][sCol] == 0)
        {
            myStack.push(visited[i][sCol]) ;
            visited[i][sCol] = 1 ;
        }
    }
    int ans = 0 ;
    if(myStack.size() == 1)return ans ;
    while(!myStack.empty())
    {
        if(myStack.top() == 0)
        {
            ans++ ;
        }
        myStack.pop() ;
    }

    return ans ;
}
int Solution :: countServers(vector<vector<int>>& grid)
{
    int row = grid.size() , col = grid[0].size() ;
    vector<vector<int>>visited(row , vector<int>(col , 0)) ;
    int ans = 0 ;
    for(int i = 0 ; i < row ; i++)
    {
        for(int j = 0 ; j < col ; j++)
        {
            if(grid[i][j] == 1)
            {
                ans += dfs(grid , i , j , visited) ;
                
            }
        }
    }
    
    return ans ;
}
