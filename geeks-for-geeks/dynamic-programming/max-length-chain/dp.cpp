bool sortByFirst(const val a , const val b)
{
    if(a.first < b.first)return true ;
    if(a.first > b.first)return false ;
    return a.second < b.second ;
}
int maxChainLen(struct val p[],int n)
{
    sort(p , p + n , sortByFirst) ;
    vector<int>dp(n , 1) ;
    for(int i = 0 ; i < n ; i++)
    {
        for(int j = 0 ; j < i ; j++)
        {
            if(p[i].first > p[j].second and dp[i] < dp[j] + 1)
            {
                dp[i] = dp[j] + 1 ;
            }
        }
    }
    return dp[n - 1] ;
}
