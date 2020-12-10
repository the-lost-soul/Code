class Solution {
public:
    int climbStairs(int n) ;
};

int Solution :: climbStairs(int n)
{
    // Base case .
    if(n == 0)return 0 ;
    if(n == 1)return 1 ;
    int stairs[n] = {} ;
    // Base cases .
    stairs[0] = 1 ;
    stairs[1] = 2 ;
    for(int i = 2 ; i < n ; i++)
    {
        // Take either one or two step .
        stairs[i] = stairs[i - 1] + stairs[i - 2] ;
    }
    return stairs[n - 1] ;
}
