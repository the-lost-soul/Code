class Solution {
public:
    string removeKdigits(string num, int k) ;
};

string Solution :: removeKdigits(string str , int k)
{
    string ans = "" ;
    for(int i = 0 ; i < str.length() ; i++)
    {
        while(ans.length() > 0 and (ans.back() > str[i] and k > 0))
        {
            ans.pop_back() ;
            k-- ;
        }
        if(ans.length() > 0 or str[i] != '0')ans.push_back(str[i]) ;
    }
    
    while(ans.size() and k > 0)
    {
        ans.pop_back() ;
        k-- ;
    }
    
    return ans.size() == 0 ? "0" : ans ;
    
}
