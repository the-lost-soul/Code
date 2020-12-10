int lps(string& str , vector<vector<int>>& dp , int start , int end)
{
    if(start > end)return 0 ;
    if(start == end)return 1 ;
    if(dp[start][end] != -1)return dp[start][end] ;
    if(str[start] == str[end])
    {
        dp[start][end] = 2 + lps(str , dp , start + 1 , end - 1) ;
    }
    else
    {
        dp[start][end] = max(lps(str , dp , start , end - 1) , 
                             lps(str , dp , start + 1  , end)) ;
    }
    return dp[start][end] ;
}

int longestPalindromeSubseq(string str)
{
    int len = str.length() ;
    vector<vector<int>>dp(len , vector<int>(len , 0)) ;
    for(int i = 0 ; i < len ; i++)
    {
        for(int j = 0 ; j < len ; j++)
        {
            dp[i][j] = -1 ;
        }
    }
    return lps(str , dp , 0 , len - 1) ;
}

bool is_k_palin(string s,int k)
{
    return s.length() - longestPalindromeSubseq(s) <= k ? 1 : 0 ;
}
