class Solution
{
    public:
        vector<vector<int>>dp ;
        int solve(string str , int i , int j)
        {
            if(i >= j)
                return 0 ;
            if(dp[i][j] != INT_MIN)
                return dp[i][j] ;
            if(str[i] == str[j])
                dp[i][j] = solve(str , i + 1 , j - 1) ;
            else
                dp[i][j] = 1 + min(solve(str , i + 1 , j) , solve(str , i , j - 1)) ;
            return dp[i][j] ;
        }
        int minimumNumberOfDeletions(string str)
        { 
            dp.resize(str.length() , vector<int>(str.length() , INT_MIN)) ;
            return solve(str , 0 , str.length() - 1) ;
        } 
};
