class Solution {
public:
    int findJudge(int N, vector<vector<int>>& trust) ;
};

int Solution :: findJudge(int N , vector<vector<int>>& trust)
{
    unordered_map<int , int>indegree , outdegree ;
    for(auto pairs : trust)
    {
        indegree[pairs[1]]++ ;
        outdegree[pairs[0]]++ ;
    }
    
    for(int person = 1 ; person <= N ; person++)
    {
        if(indegree[person] == N - 1 and outdegree.find(person) == outdegree.end())
            return person ;
    }
    return -1 ;
}
