class Solution {
public:
    int smallestRepunitDivByK(int K) ;
};

int Solution :: smallestRepunitDivByK(int K)
{
    // If K is even or multiple of 5 , then no number having 
    // only 1 is possible .
    if(K % 2 == 0 || K % 5 == 0)return -1 ;
    
    
    // Start with smallest possible number i.e 1
    int n = 1 ;
    int length = 1 ;
    unordered_set<int>remainder ;
    
    /* The reason for iterating till K is that as we know on taking modulo of a number by 'K'
     * ,we will get remainder between 0 to k - 1 , and hence till K iteration if we don't get 
     * a number which is divisible by 'K' , then after 'K' iteration also we will get the 
     * same result i.e we will be caught inside a loop not be able to find a number which
     * is dividible by 'K' .
     */
    for(int i = 1 ; i <= K ; i++)
    {
        // In place of length we can simply return i as the length of smallest number will be
        // in between 0 to K - 1 .
        if(n % K == 0) return length ;
        
        
        // Since at each iteration we get a different result and hence if at any point we get
        // remainder which we have already calculated then that means there is a loop and hence
        // the given number is not divisible by "K" .
        if(remainder.find(n % K) != remainder.end()) return -1 ;
        
        // Both are same .
        // n = (n*10 + 1) % K ; 
        n = ((n % K) * (10 % K) + 1) ;
        length ++ ;
    }
    
    return -1 ;
    

}
