class Solution {
public:
    vector<bool> camelMatch(vector<string>& queries, string pattern) ;
    bool check(string pattern , string query) ;
};

bool Solution :: check(string pattern , string query)
{
    int i = 0 ;
    for(auto ch : query)
    {
        if(isupper(ch) and pattern[i] != ch)
            return false ;
        else if(ch == pattern[i])
            i++ ;  
    }
    return i == pattern.length() ;
}

vector<bool> Solution :: camelMatch(vector<string>& queries , string pattern)
{
    vector<bool>result ;
    for(auto str : queries)
    {
        result.push_back(check(pattern , str)) ;
    }
    return result ;
}
