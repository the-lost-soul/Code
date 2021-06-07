class Solution {
    vector<vector<pair<int , int>>>adjList ;
    vector<bool>visited ;
    int change ;
public:
    int minReorder(int n, vector<vector<int>>& connections) ;
    bool dfs(int u , int p) ;
};
bool Solution :: dfs(int u , int p)
{
    visited[u] = true ;
    for(auto node : adjList[u])
    {
        if(node.first != p and visited[node.first] == false)
        {
            change += node.second ;
            dfs(node.first , u) ;
        }
    }
    return true ;
}

int Solution :: minReorder(int n , vector<vector<int>>& connections)
{
    adjList.resize(n) ;
    visited.resize(n) ;
    for(auto edge : connections)
    {
        adjList[edge[0]].push_back({edge[1] , 1}) ;
        adjList[edge[1]].push_back({edge[0] , 0}) ;
    }
    
    dfs(0 , -1) ;
    return change ;
}
