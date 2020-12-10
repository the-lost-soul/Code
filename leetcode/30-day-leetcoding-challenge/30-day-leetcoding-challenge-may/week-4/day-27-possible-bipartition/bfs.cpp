class Solution 
{
    enum COLOR{red , black , white} ;
    vector<enum COLOR>color ;
    vector<vector<int>>adjList ;
    vector<bool>visited ;
public:
    bool possibleBipartition(int N, vector<vector<int>>& dislikes) ;
    bool isBipartite(int u) ;
};

bool Solution :: isBipartite(int u)
{
    color[u] = black ;
    queue<int>myQueue ;
    myQueue.push(u) ;
    while(!myQueue.empty())
    {
        for(auto ele : adjList[myQueue.front()])
        {
            if(visited[ele] == false)
            {
                visited[ele] = true ;
                if(color[myQueue.front()] == black)
                {
                    color[ele] = red ;
                }
                else
                {
                    color[ele] = black ;
                }
                myQueue.push(ele) ;
            }
            else if(color[myQueue.front()] == color[ele])
            {
                return false ;
            }
        }
        myQueue.pop() ;
    }
    return true ;
}

bool Solution :: possibleBipartition(int nodes , vector<vector<int>>& dislikes)
{
    color.resize(nodes + 1 , white) ;
    adjList.resize(nodes + 1) ;
    for(auto edge : dislikes)
    {
        int node1 = edge[0] , node2 = edge[1] ;
        adjList[node1].push_back(node2) ;
        adjList[node2].push_back(node1) ;
    }
    visited.resize(nodes + 1 , false) ;
    bool ans = true ;
    for(int i = 1 ; i <= nodes ; i++)
    {
        if(visited[i] == false)
        {
            ans = ans and isBipartite(i) ;
        }
    }
    return ans ;
}
