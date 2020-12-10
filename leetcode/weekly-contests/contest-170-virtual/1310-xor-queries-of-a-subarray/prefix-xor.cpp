class Solution {
public:
    vector<int> xorQueries(vector<int>& arr, vector<vector<int>>& queries) ;
};

vector<int> Solution :: xorQueries(vector<int>& arr , vector<vector<int>>& queries)
{
    vector<int> xorVec ;
    int tempXor = 0 ;
    int len = arr.size() ;
    for(int i = 0 ; i < len ; i++)
    {
        tempXor ^= arr[i] ;
        xorVec.push_back(tempXor) ;
    }
    
    int queryLen = queries.size() ;
    vector<int> xorSub ;
    for(int i = 0 ; i < queryLen ; i++)
    {
        int l = queries[i][0] , r = queries[i][1] ;
        int currXor = xorVec[l]^xorVec[r]^arr[l] ;
        xorSub.push_back(currXor) ;
    }
    return xorSub ;
}
