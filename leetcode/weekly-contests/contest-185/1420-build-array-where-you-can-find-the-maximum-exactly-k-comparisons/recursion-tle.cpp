class Solution {
public:
    const int mod = 1e9 + 7 ;
    int numOfArrays(int n, int m, int k) ;
    int helper(int prevMax , int n , int m , int k) ;
};

int Solution :: helper(int prevMax , int n , int m , int k)
{
    if(n == 0 and k == 0)return 1 ;
    if(n <= 0)return 0 ;
    int count = 0 ;
    for(int ele = 1 ; ele <= m ; ele++)
    {
        int cost = k ;
        if(ele > prevMax)
        {
            prevMax = ele ;
            cost-- ;
        }
        count = (count + helper(prevMax , n - 1 , m , cost))%mod ;
    }
    return count ;
}
int Solution :: numOfArrays(int n , int m , int k)
{
    int prevMax = INT_MIN ;
    return helper(prevMax , n , m , k) ;
}
