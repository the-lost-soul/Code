class Solution {
public:
    string toLowerCase(string str) ;
};

string Solution :: toLowerCase(string str)
{
    string ans = "" ;
    for(auto ch : str)
    {
        if(isupper(ch))
        {
            ans += (ch - 'A') + 'a';
            continue ;
        }
        ans += ch ;
    }
    return ans ;
}
