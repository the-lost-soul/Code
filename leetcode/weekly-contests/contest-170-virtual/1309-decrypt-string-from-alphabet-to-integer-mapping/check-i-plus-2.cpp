class Solution {
public:
    string freqAlphabets(string s) ;
};

string Solution :: freqAlphabets(string s)
{
    int len = s.length() , i = 0 ;
    string ans = ""  , refer = "0abcdefghijklmnopqrstuvwxyz";
    while(i < len)
    {
        int charPlace = 0 ;
        if(i + 2 < len and s[i + 2] == '#')
        {
            charPlace = (s[i] - '0')*10 + (s[i + 1] - '0') ;
            ans += refer[charPlace] ;
            i += 2 ;
        }
        else
        {
            charPlace = s[i] - '0' ;
            ans += refer[charPlace] ;
        }
        i++ ;
    }
    return ans ;
}
