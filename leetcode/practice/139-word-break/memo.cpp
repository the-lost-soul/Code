class Solution
{
    unordered_set<string>hash ;
    vector<int>dp ;
public:
    bool solve(string s , int idx)
    {
        if(idx >= s.length())
            return true ;
        if(dp[idx] != -1)
            return dp[idx] ;
        for(int i = idx ; i < s.length() ; i++)
        {
            const string curr = s.substr(idx , i - idx + 1) ;
            if(hash.find(curr) != hash.end())
                if(solve(s , i + 1))
                {
                    dp[idx] = 1 ;
                    return true ;
                }
        }
        dp[idx] = 0 ;
        return false ;
    }

    bool wordBreak(string s, vector<string>& wordDict)
    {
        for(auto str : wordDict)
            hash.insert(str) ;

        dp.resize(s.length() , -1) ;
        return solve(s , 0) ;
    }
};
