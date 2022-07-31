class Solution 
{
    const int mod = 1e9 + 7 ;
public:
    int numberWays(vector<vector<int>>& hats) ;
    int helper(vector<vector<int>>& hats , vector<int> visited , int ind) ;
};

int Solution :: helper(vector<vector<int>>& hats , vector<int> visited , int ind)
{
    if(ind == hats.size())
        return 1 ;
    if(ind > hats.size())
        return 0 ;
    
    int count = 0 ;
    for(int i = 0 ; i < hats[ind].size() ; i++)
    {
        int hatNum = hats[ind][i] ;
        if(visited[hatNum] == 0)
        {
            visited[hatNum] = 1 ;
            count = (count%mod + helper(hats , visited , ind + 1)%mod)%mod ;
            visited[hatNum] = 0 ;
        }
    }
    return count ;
}

int Solution :: numberWays(vector<vector<int>>& hats)
{
    vector<int>visited(41 , 0) ;
    return helper(hats , visited , 0) ;
}
