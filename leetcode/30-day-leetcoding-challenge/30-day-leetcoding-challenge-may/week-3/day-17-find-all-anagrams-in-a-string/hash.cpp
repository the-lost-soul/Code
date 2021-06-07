class Solution {
public:
    vector<int> findAnagrams(string s, string p) ;
};

vector<int> Solution :: findAnagrams(string s , string p)
{
    if(p.length() > s.length())return {} ;
    vector<int>countP(26 , 0) ;
    for(auto ch : p)
        countP[ch - 'a']++ ;
    vector<int>countS(26 , 0) ;
    for(int i = 0 ; i < p.size() ; i++)
    {
        countS[s[i] - 'a']++ ;
    }
    
    vector<int>ans ;
    if(countP == countS) ans.push_back(0) ;
    for(int i = p.size() ; i < s.size() ; i++)
    {
        countS[s[i - p.size()] - 'a']-- ;
        countS[s[i] - 'a']++ ;
        if(countS == countP)ans.push_back(i - p.size() + 1) ;
    }
    return ans ;
}
