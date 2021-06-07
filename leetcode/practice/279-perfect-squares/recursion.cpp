class Solution {
public:
    int numSquares(int n) ;
};
int Solution :: numSquares(int n)
{
    if(n == 0)return 0 ;
    int ans = n ;
    int num = 2 ;
    while(num*num <= n)
    {
        int count = n/(num*num) , newNum = n%(num*num) ;
        ans = min(ans , count + numSquares(newNum)) ;
        num++ ;
    }
    return ans ;
}
