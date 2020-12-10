class Solution 
{
    const int mod = 1e9 + 7 ;
    vector<vector<int>>dp ;
public:
    int numberWays(vector<vector<int>>& hats) ;
    int helper(vector<vector<int>> wear , int allAssigned , int chosen , int hat) ;
};

int Solution :: helper(vector<vector<int>> wear , int allAssigned , int chosen , int hat)
{
    if(chosen == allAssigned)return 1 ;
    if(hat > 40)return 0 ;
    if(dp[hat][chosen] != -1)return dp[hat][chosen] ;
    
    int count = helper(wear , allAssigned , chosen , hat + 1) ;

    for(auto person : wear[hat])
    {
        if(((chosen >> person)&1) == 1) continue ;
        count = (count + helper(wear , allAssigned , chosen | (1 << person) , hat + 1))%mod ;
    }
    return dp[hat][chosen] = count ;
}

int Solution :: numberWays(vector<vector<int>>& hats)
{
    dp.resize(41 , vector<int>(1024 , -1)) ;
    vector<vector<int>>wear(41) ;
    for(int i = 0 ; i < hats.size() ; i++)
    {
        for(auto hatNum : hats[i])
        {
            wear[hatNum].push_back(i) ;
        }
    }
    int allAssigned = (1 << hats.size()) - 1 ;
    return helper(wear , allAssigned , 0 , 1) ;
}
