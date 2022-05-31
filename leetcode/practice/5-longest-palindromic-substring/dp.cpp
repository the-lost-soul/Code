class Solution
{
public:
    string longestPalindrome(string s)
    {
        int dp[s.size()][s.size()] ;

        // palindrome of length 1 .
        for(int i = 0 ; i < s.size() ; i++)
            dp[i][i] = 1 ;

        int maxlen = 1 , startInd = 0 ;
        // palindrome of length 2 .
        for(int i = 0 ; i < s.size() - 1  ; i++)
        {
            dp[i][i + 1] = s[i] == s[i + 1] ;
            if(dp[i][i + 1] and maxlen < 2)
            {
                maxlen = 2 ;
                startInd = i ;
            }
        }

        for(int len = 3 ; len <= s.size() ; len++)
        {
            for(int i = 0 ; i < s.size() - len + 1 ; i++)
            {
                int j = len + i - 1 ;
                dp[i][j] = dp[i + 1][j - 1] and (s[i] == s[j]) ;
                if(dp[i][j] and maxlen < len)
                {
                    startInd = i ;
                    maxlen = len ;
                }
            }
        }
        return s.substr(startInd , maxlen) ;
    }
};
