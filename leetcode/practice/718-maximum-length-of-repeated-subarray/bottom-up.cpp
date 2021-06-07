class Solution {
public:
    int findLength(vector<int>& arr1 , vector<int>& arr2) ;
};

int Solution :: findLength(vector<int>& arr1 , vector<int>& arr2)
{
    int len1 = arr1.size() , len2 = arr2.size() ;
    vector<vector<int>>dp(len1 + 1 , vector<int>(len2 + 1 , 0)) ;
    for(int i = 0 ; i <= len1 ; i++)
        dp[i][0] = 0 ;
    for(int i = 0 ; i <= len2 ; i++)
        dp[0][i] = 0 ;
    
    for(int i = 1 ; i <= len1 ; i++)
    {
        for(int j = 1 ; j <= len2 ; j++)
        {
            if(arr1[i - 1] == arr2[j - 1])
            {
                dp[i][j] = 1 + dp[i - 1][j - 1] ;
            }
        }
    }
    int ans = INT_MIN ;
    for(int i = 0 ; i <= len1 ; i++)
    {
        for(int j = 0 ; j <= len2 ; j++)
        {
            ans = max(ans , dp[i][j]) ;
        }
    }
    return ans ;
}
