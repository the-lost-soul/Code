class Solution {
public:
    int minInsertions(string s) ;
};
int longestPallindromicSubseq(string s)
{
    int len = s.size() ;
    int dp[len][len] = {} ;
    for(int i = 0 ; i < len; i++)
        dp[i][i] = 1 ;
    for(int dist = 2 ; dist <= len ; dist++)
    {
        for(int i = 0 ; i <= len - dist ; i++)
        {
            int j = i + dist - 1 ;
            if(s[i] == s[j])
                dp[i][j] = 2 + dp[i + 1][j - 1] ;
            else dp[i][j] = max(dp[i + 1][j] , dp[i][j - 1]) ;
        }
    }
    return dp[0][len - 1] ;
}
int Solution :: minInsertions(string s)
{
    int lps = longestPallindromicSubseq(s) ;
    return s.size() - lps ;
}
