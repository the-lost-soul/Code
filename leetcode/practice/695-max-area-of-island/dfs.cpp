class Solution {
public:
    int maxArea ;
    int startRow , startCol ;
    int maxAreaOfIsland(vector<vector<int>>& grid) ;
    int dfs(vector<vector<int>>& grid , vector<vector<bool>>& visited) ;
    bool validMove(int currRow , int currCol , int row , int col) ;
};
bool Solution :: validMove(int currRow , int currCol , int row , int col)
{
    return currRow>=0 and currCol>= 0 and currRow < row and currCol < col ;
}
int Solution :: dfs(vector<vector<int>>& grid ,vector<vector<bool>>&visited)
{
    stack<pair<int , int>>myStack ;
    myStack.push({startRow , startCol}) ;
    visited[startRow][startCol] = true ;
    int area = 0 ;
    while(!myStack.empty())
    {
        auto info = myStack.top() ;
        myStack.pop() ;
        int currRow = info.first , currCol = info.second ;
        area++ ;
        if(validMove(currRow - 1 , currCol , grid.size() , grid[0].size()))
        {
            if(grid[currRow - 1][currCol] and !visited[currRow-1][currCol])
            {
                myStack.push({currRow - 1 , currCol}) ;
                visited[currRow - 1][currCol] = true ;
            }
        }
        
        if(validMove(currRow + 1 , currCol , grid.size() , grid[0].size()))
        {
            if(grid[currRow + 1][currCol] and !visited[currRow+1][currCol])
            {
                myStack.push({currRow + 1 , currCol}) ;
                visited[currRow + 1][currCol] = true ;
            }
        }
        
        if(validMove(currRow , currCol - 1 , grid.size() , grid[0].size()))
        {
            if(grid[currRow][currCol - 1] and !visited[currRow][currCol-1])
            {
                myStack.push({currRow , currCol - 1}) ;
                visited[currRow][currCol - 1] = true ;
            }
        }
        
        if(validMove(currRow , currCol + 1 , grid.size() , grid[0].size()))
        {
            if(grid[currRow][currCol+1] and !visited[currRow][currCol+1])
            {
                myStack.push({currRow , currCol + 1}) ;
                visited[currRow][currCol + 1] = true ;   
            }
        }  
    }
    return area ;
}
int Solution :: maxAreaOfIsland(vector<vector<int>>& grid)
{
    maxArea = INT_MIN ;
    int row = grid.size() , col = grid[0].size() ;
    vector<vector<bool>>visited(row , vector<bool>(col , false)) ;
    for(int i = 0 ; i < row ; i++)
    {
        for(int j = 0 ; j < col ; j++)
        {
            if(grid[i][j] and !visited[i][j])
            {
                startRow = i ;
                startCol = j ;
                maxArea = max(maxArea , dfs(grid , visited)) ;
            }
        }
    }
    return maxArea == INT_MIN ? 0 : maxArea ;
}
