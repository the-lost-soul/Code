class Solution {
public:
    int countSubstrings(string s) ;
};

int Solution :: countSubstrings(string s)
{
    int len = s.length() ;
    int dp[len][len] ;
    memset(dp , 0 , sizeof(dp)) ;
    int ans = 0 ;
    // All string of length 1 is pallindrome .
    for(int i = 0 ; i < len ; i++)
    {
        dp[i][i] = 1 ;
        ans++ ;
    }
    // Check of strings of length 2 .
    for(int i = 0 ; i < len - 1 ; i++)
    {
        if(s[i] == s[i+1])
        {
            dp[i][i+1] = 1 ;
            ans++ ;
        }
    }
    // Check of string of length greater than equal to 3 .
    for(int length = 3 ; length <= len ; length++)
    {
        for(int i = 0 ; i <= len - length ; i++)
        {
            int j = i + length - 1 ;
            // If the first and last character of current string matches
            // and s[i+1,...,j-1]is a pallindrome then string[si,...j] is
            // also a pallindrome  .
            if(dp[i + 1][j - 1] and s[i]==s[j])
            {
                dp[i][j] = 1 ;
                ans++ ;
            }
        }
        
    }
    return ans ;
    
}
