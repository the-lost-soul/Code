class Solution {
public:
    vector<string> findAndReplacePattern(vector<string>& words, string pattern) ;
    string normalise(string s) ;
};

string Solution :: normalise(string s)
{
    unordered_map<char , int>hash ;
    for(auto ch : s)
    {
        if(hash.find(ch) == hash.end())
            hash[ch] = hash.size() ;
    }
    for(int i = 0 ; i < s.length() ; i++)
    {
        s[i] = 'a' + hash[s[i]] ;
    }
    return s ;
}

vector<string> Solution :: findAndReplacePattern(vector<string>& words , string pattern)
{
    string normalPatt = normalise(pattern) ;
    vector<string>res ;
    for(auto w : words)
    {
        string normalWord = normalise(w) ;
        if(normalWord == normalPatt)
            res.push_back(w) ;
    }
    return res ;   
}
