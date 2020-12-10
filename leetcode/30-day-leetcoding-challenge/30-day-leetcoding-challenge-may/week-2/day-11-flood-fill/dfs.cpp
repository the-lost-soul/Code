class Solution {
    vector<vector<bool>> visited ;
    vector<vector<int>> clone ;
    int replace ;
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) ;
    void dfs(int sr , int sc , int newColor) ;
    bool legal(int sr , int sc)
    {
        if(sr >= 0 and sr < clone.size() and sc >= 0 and sc < clone[0].size()) 
            return true ;
        return false ;
    }
};
void Solution :: dfs(int sr , int sc , int newColor)
{
    if(visited[sr][sc])return ;
    visited[sr][sc] = true ;
    if(clone[sr][sc] == replace)
    {
        clone[sr][sc] = newColor ;
    }
    if(legal(sr + 1 , sc))
    {
        if(clone[sr + 1][sc] == replace)
            dfs(sr + 1 , sc , newColor) ;
    }
    
    if(legal(sr - 1 , sc))
    {
        if(clone[sr - 1][sc] == replace)
            dfs(sr - 1 , sc , newColor) ;
    }
    
    if(legal(sr , sc + 1))
    {
        if(clone[sr][sc + 1] == replace)
            dfs(sr , sc + 1 , newColor) ;
    }
    
    if(legal(sr , sc - 1))
    {
        if(clone[sr][sc - 1] == replace)
            dfs(sr , sc - 1 , newColor) ;
    }
}

vector<vector<int>> Solution :: floodFill(vector<vector<int>>& image , int sr , int sc , int newColor)
{
    int row = image.size() , col = image[0].size() ;
    replace = image[sr][sc] ;
    visited.resize(row , vector<bool>(col , false)) ;
    clone = image ;
    dfs(sr , sc , newColor) ;
    return clone ;
}
