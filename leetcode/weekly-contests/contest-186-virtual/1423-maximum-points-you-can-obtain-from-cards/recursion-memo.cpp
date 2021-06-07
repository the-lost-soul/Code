class Solution {
    vector<vector<int>> dp ;
    long ans = -1 ;
public:
    int maxScore(vector<int>& cardPoints, int k) ;
    int helper(vector<int>& cardPoints , int k , int l , int r , long sum) ;
};

int Solution :: helper(vector<int>& cardPoints , int k , int l , int r , long sum)
{
    if(k == 0)
    {
        ans = max(ans , sum) ;
        return ans ;
    }
    if(dp[l][r] != -1) return dp[l][r] ;
    if(l < cardPoints.size())
    {
        dp[l][r] = helper(cardPoints , k - 1 , l + 1 , r , sum + cardPoints[l]) ;
    }
    
    if(r >= 0)
    {
        dp[l][r] = max(dp[l][r] , helper(cardPoints , k - 1 , l , r - 1 , sum + cardPoints[r])) ;
    }
    return dp[l][r] ;
}

int Solution :: maxScore(vector<int>& cardPoints , int k)
{
    int left = 0 , right = cardPoints.size() - 1 ;
    long sum = 0 ;
    dp.resize(right + 1 , vector<int>(right + 1 , -1)) ;
    helper(cardPoints , k , left , right , sum) ;
    return dp[left][right] ;
}
