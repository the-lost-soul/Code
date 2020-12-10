class Solution {
public:
    vector<string> printVertically(string s) ;
};

vector<string> Solution :: printVertically(string s)
{
    stringstream ss(s) ;
    s = "" ;
    vector<string>words ;
    int maxLen = INT_MIN ;
    while(ss >> s)
    {
        words.push_back(s) ;
        maxLen = max(maxLen , (int)s.length()) ;
    }
    
    vector<string>ans(maxLen , "") ;
    for(int i = 0 ; i < maxLen ; i++)
    {
        for(auto w : words)
        {
            ans[i] += i < w.length() ? w[i] : ' ' ;
        }
        
        while(ans[i].back() == ' ')
            ans[i].pop_back() ;
    }
    return ans ;
}
