class Solution {
    int ans = 0 ;
    unordered_map<int , vector<int>>nodes ;
    vector<bool>visited ;
public:
    int minTime(int n, vector<vector<int>>& edges, vector<bool>& hasApple) ;
    bool helper(int n , vector<bool>& hasApples , int root) ;
};

bool Solution :: helper(int n , vector<bool>& hasApple , int root)
{
    if(visited[root])
        return false ;
    visited[root] = true ;
    bool increment = hasApple[root] ;
    for(auto child : nodes[root])
    {
        bool cond = helper(n , hasApple , child) ;
        if(cond) ans += 2 ;
        increment = cond or increment ;
    }
    
    return increment ;
}

int Solution :: minTime(int n , vector<vector<int>>& edges , vector<bool>& hasApple)
{
    visited.resize(n , false) ;
    for(auto ele : edges)
    {
        nodes[ele[0]].push_back(ele[1]) ;
        nodes[ele[1]].push_back(ele[0]) ;
    }
    bool temp = helper(n , hasApple , 0) ;
    return ans ;
}
