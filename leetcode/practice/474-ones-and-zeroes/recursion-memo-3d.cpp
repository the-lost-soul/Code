class Solution {
public:
    unordered_map<string , pair<int , int>>count ;
    vector<vector<vector<int>>>dp ;
    int findMaxForm(vector<string>& strs, int m, int n) ;
    int helper(vector<string>& strs , int m , int n , int index) ;
};

int Solution :: helper(vector<string>& strs , int m , int n ,int index)
{
    if(m <= 0 and n <= 0)
        return 0 ;
    if(index >= strs.size())
        return 0 ;
    if(dp[m][n][index] != -1)
        return dp[m][n][index] ;
    int zeroes = count[strs[index]].first , ones = count[strs[index]].second ;
    int ans1 = 0 ;
    if(m >= zeroes and n >= ones)
        ans1 = 1 + helper(strs , m - zeroes , n - ones , index + 1) ;
    int ans2 = helper(strs , m , n , index + 1) ;
    return dp[m][n][index] = max(ans1 , ans2) ;
    
}

int Solution :: findMaxForm(vector<string>& strs , int m , int n)
{
    dp.resize(m + 1 , vector<vector<int>>(n + 1 , vector<int>(strs.size() , -1))) ;
    for(auto s : strs)
    {
        int count0 = 0 , count1 = 0 ;
        for(auto ch : s)
            ch == '0' ? count0++ : count1++ ;
        count[s] = {count0 , count1} ;
    }
    dp[m][n][0] = helper(strs , m , n , 0) ;
    return dp[m][n][0] ;
}
