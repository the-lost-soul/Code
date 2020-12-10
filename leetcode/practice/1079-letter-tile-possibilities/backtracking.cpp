class Solution 
{
    unordered_set<string>hash ;
    string text ;
public:
    int numTilePossibilities(string tiles) ;
    void helper(string tiles , vector<bool>visited) ;
};

void Solution :: helper(string tiles , vector<bool>visited)
{
    int ans = 0 ;
    for(int i = 0 ; i < visited.size() ; i++)
    {
        if(visited[i])continue ;
        text.push_back(tiles[i]) ;
        hash.insert(text) ;
        visited[i] = true ;
        helper(tiles , visited) ;
        text.pop_back() ;
        visited[i] = false ;
    }
    
}

int Solution :: numTilePossibilities(string tiles)
{
    int len = tiles.size() ;
    vector<bool>visited(len , false) ;
    helper(tiles , visited) ;
    return hash.size() ;
}
