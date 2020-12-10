class Solution 
{
    vector<int>dp ;
    public:
        bool canReach(vector<int>& arr, int start) ;
        bool helper(vector<int>& arr , int currInd) ;
};

bool Solution :: helper(vector<int>& arr , int currInd)
{
    if(currInd < 0 or currInd >= arr.size())
        return false ;
    if(dp[currInd] != 0)return false ;
    if(arr[currInd] == 0)return true ;
    dp[currInd] = 1 ;
    return helper(arr , currInd - arr[currInd]) or helper(arr , currInd + arr[currInd]) ;
}

bool Solution :: canReach(vector<int>& arr , int start)
{
    dp.resize(arr.size() , 0) ;
    if(arr[start] == 0)return true ;
    dp[start] = 1 ;
    return helper(arr , start - arr[start]) or helper(arr , start + arr[start]) ; 
}
