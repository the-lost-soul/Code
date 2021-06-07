class Solution {
public:
    string smallestSubsequence(string text) ;
};

string Solution :: smallestSubsequence(string text)
{
    vector<int>count(26 , 0) ;
    for(auto ch : text)
        count[ch - 'a']++ ;
    
    vector<bool>visited(26 , false) ;
    vector<char>ans ;
    for(auto ch : text)
    {
        if(visited[ch - 'a'])
        {
            count[ch - 'a'] -= 1 ;
            continue ;
        }
        while(ans.size() > 0 and ans.back() >= ch and count[ans.back() - 'a'] > 0)
        {
            visited[ans.back() - 'a'] = false ;
            ans.pop_back() ;
        }
        ans.push_back(ch) ;
        visited[ch - 'a'] = true ;
        count[ch - 'a']-- ;
    }
    string res = "" ;
    for(auto ch : ans)
        res += ch ;
    return res ;
}
