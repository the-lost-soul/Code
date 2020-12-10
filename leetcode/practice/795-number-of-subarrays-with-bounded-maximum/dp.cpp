class Solution {
public:
    int numSubarrayBoundedMax(vector<int>& arr , int lowerLim , int upperLim) ;
};

int Solution :: numSubarrayBoundedMax(vector<int>& arr , int lower , int upper)
{
    int len = arr.size() , prev = -1 ;
    int dp[len] ;
    memset(dp , 0 , sizeof(dp)) ;
    for(int i = 0 ; i < len ; i++)
    {
        if(arr[i] >= lower and arr[i] <= upper)
        {
            dp[i] += (i - prev) ;
        }
        else if(arr[i] > upper)
        {
            prev = i ;
            dp[i] = 0 ;   
        }
        else
        {
            dp[i] = i != 0 ? dp[i - 1] : 0 ;
        }
    }
    return accumulate(dp , dp + len , 0) ;
}
