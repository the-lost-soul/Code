class Solution {
    unordered_map<int , vector<int>>topSort ;
    vector<vector<int>> dp ;
    vector<bool>res ;
public:
    vector<bool> checkIfPrerequisite(int n, vector<vector<int>>& prerequisites, vector<vector<int>>& queries) ;
    bool helper(int dep , int u) ;
    
} ;

bool Solution :: helper(int u , int v)
{
    if(dp[u][v] != -1)return dp[u][v] ;
    for(auto node : topSort[u])
    {
        if(v == node)return dp[u][v] = 1 ;
        if(helper(node , v))return dp[node][v] = 1 ;  
    }
    return dp[u][v] = 0 ;
}

vector<bool> Solution :: checkIfPrerequisite(int n, vector<vector<int>>& preReq, vector<vector<int>>& queries)
{
    dp.resize(n , vector<int>(n , -1)) ;
    for(auto edge : preReq)
    {
        topSort[edge[1]].push_back(edge[0]) ;
        dp[edge[1]][edge[0]] = 1 ;
    }
    
    for(auto q : queries)
    {
        int sub1 = q[0] , sub2 = q[1] ;
        bool ans = helper(sub2 , sub1) ;
        res.push_back(ans) ;
    }
    return res ;
}
