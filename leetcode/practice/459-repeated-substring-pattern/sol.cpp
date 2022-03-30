class Solution {
public:
    bool repeatedSubstringPattern(string s)
    {
        int n = s.size() ;
        string str = "" ;
        for(int len = 1 ; len <= n/2 ; len++)
        {
            // get the first repeated part .
            str += s[len - 1] ;
            int j = len ;
            // check if the above string is repeated more than once
            // and forms the whole string .
            while(j <= n - len)
            {
                string temp = s.substr(j , len) ;
                if(str == temp)
                {
                    if(j + len == n)
                        return true ;
                    j += len ;
                }
                else
                    break ;
            }
        }
        return false ;
    }
};
