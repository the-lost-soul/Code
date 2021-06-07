class Solution {
public:
    int numSquares(int n) ;
};

int Solution :: numSquares(int n)
{
    if(n == 1)return 1 ;
    if(n == 0)return 0 ;
    if(n < 0)return n + 1 ;
    int ans = n + 1 ;
    for(int i = 1 ; i*i <= n ; i++)
    {
        ans = min(ans , 1 + numSquares(n - i*i)) ;
    }
    return ans ;
}
