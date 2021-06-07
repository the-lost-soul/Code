class Solution {
    unordered_map<string , bool>hash ;
public:
    bool hasAllCodes(string s, int k) ;
};

bool Solution :: hasAllCodes(string str , int k)
{
    string code = "" ;
    for(int i = 0 ; i < k ; i++)code += str[i] ;
    int ans = 1 ;
    hash[code] = true ;
    int maxLim = pow(2 , k) ;
    for(int i = k ; i < str.size() ; i++)
    {
        code.erase(code.begin()) ;
        code += str[i] ;
        if(hash.find(code) == hash.end())
        {
            hash[code] = true ;
            ans++ ;
        }
        if(ans == maxLim)break ;
    }
    return ans == maxLim ;
}
