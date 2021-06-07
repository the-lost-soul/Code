class Solution {
public:
    int findMaxForm(vector<string>& strs, int m, int n) ;
};

int Solution :: findMaxForm(vector<string>& strs , int m , int n)
{
    vector<vector<int>>dp(m + 1 , vector<int>(n + 1 , 0)) ;
    for(auto s : strs)
    {
        int zeroes = count(begin(s) , end(s) , '0') ;
        int ones = s.length() - zeroes ;
        
        for(int i = m ; i >= zeroes ; i--)
            for(int j = n ; j >= ones ; j--)
                dp[i][j] = max(dp[i][j] , dp[i - zeroes][j - ones] + 1) ;
    }
    return dp[m][n];
}
