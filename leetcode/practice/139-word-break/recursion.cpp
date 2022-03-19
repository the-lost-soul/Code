class Solution
{
    unordered_set<string>hash ;
public:
    bool solve(string s , int idx)
    {
        if(idx >= s.length())
            return true ;
        for(int i = idx ; i < s.length() ; i++)
        {
            string curr = s.substr(idx , i - idx + 1) ;
            if(hash.find(curr) != hash.end() and solve(s , i + 1))
                return true ;
        }
        return false ;
    }

    bool wordBreak(string s, vector<string>& wordDict)
    {
        for(auto str : wordDict)
            hash.insert(str) ;

        return solve(s , 0) ;
    }
};
