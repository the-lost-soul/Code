class Solution {
public:
    int climbStairs(int n) ;
};

int Solution :: climbStairs(int n)
{
    // Base case .
    if(n == 0)return 0 ;
    if(n == 1)return 1 ;
    // Base cases .
    int first = 1 ;
    int second = 2 ;
    for(int i = 2 ; i < n ; i++)
    {
        // Take either one or two step .
        int third = first + second ;
        first = second ;
        second = third ;
    }
    // We are not returning var "third" , because it's scope is only in the 
    // for loop .
    return second ;
}
