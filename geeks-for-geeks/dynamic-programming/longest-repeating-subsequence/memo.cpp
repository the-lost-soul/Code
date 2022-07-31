class Solution
{
	public:
        vector<vector<int>> dp ;
        int solve(string str , int i , int j)
        {
            if(i >= str.length() || j >= str.length())
                return 0 ;
            if(dp[i][j] != INT_MIN)
                return dp[i][j] ;

            if(str[i] == str[j] and i != j)
                dp[i][j] = 1 + solve(str , i + 1 , j + 1) ;
            else 
                dp[i][j] = max(solve(str , i + 1 , j) , solve(str , i , j + 1)) ;
            return dp[i][j] ;
        }
		int LongestRepeatingSubsequence(string str)
        {
            dp.resize(str.size() , vector<int>(str.size() , INT_MIN)) ;
            return solve(str , 0 , 0) ;
		}

};
