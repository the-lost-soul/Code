class Solution {
    vector<vector<int>>adjList ;
    vector<int>inDegree ;
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) ;
};

bool Solution :: canFinish(int numCourses , vector<vector<int>>& pre)
{
    adjList.resize(numCourses) ;
    inDegree.resize(numCourses , 0) ;
    for(auto edges : pre)
    {
        int node1 = edges[0] , node2 = edges[1] ;
        adjList[node1].push_back(node2) ;
        inDegree[node2]++ ;
    }
    queue<int>q ;
    for(int i = 0 ; i < numCourses ; i++)
    {
        if(inDegree[i] == 0)q.push(i) ;
    }
    while(!q.empty())
    {
        int node = q.front() ;
        q.pop() ;
        numCourses-- ;
        for(auto ele : adjList[node])
        {
            inDegree[ele]-- ;
            if(inDegree[ele] == 0)q.push(ele) ;
        }
    }
    return numCourses == 0 ;
}
