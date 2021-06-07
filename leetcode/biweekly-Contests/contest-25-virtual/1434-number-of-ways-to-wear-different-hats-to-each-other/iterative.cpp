class Solution 
{
    const int mod = 1e9 + 7 ;
public:
    int numberWays(vector<vector<int>>& hats) ;
};

int Solution :: numberWays(vector<vector<int>>& hats)
{
    vector<vector<int>>wear(41) ;
    for(int i = 0 ; i < hats.size() ; i++)
    {
        for(auto hatNum : hats[i])
        {
            wear[hatNum].push_back(i) ;
        }
    }
    int allAssigned = (1 << hats.size()) - 1 ;
    vector<vector<int>>dp(41 , vector<int>(allAssigned + 1 , 0)) ;
    dp[0][0] = 1 ;
    for(int hat = 1 ; hat <= 40 ; hat++)
    {
        for(int mask = 0 ; mask <= allAssigned ; mask++)
        {
            dp[hat][mask] = (dp[hat][mask] + dp[hat - 1][mask])%mod ;
            for(auto person : wear[hat])
            {
                if(mask & (1 << person))
                {
                    dp[hat][mask] = (dp[hat][mask] + dp[hat - 1][mask xor (1 << person)])%mod ;
                }
            }
        }
    }
    return dp[40][allAssigned] ;
}
