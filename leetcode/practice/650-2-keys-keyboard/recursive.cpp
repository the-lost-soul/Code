class Solution {
public:
    int n ;
    int minSteps(int n) ;
    int helper(int length , int copy) ;
};
int Solution :: helper(int length , int copy)
{
    if(length >= n)return 0 ;
    
    /* If length of current number of A's divides the desired number of A's
     * then , we can either perform copy or paste operation depending on the
     * number of A's copied earlier and current number of A's .
     */
    if(n%length == 0)
    {
        /* If current length of A's and number of A's copied lastly are equal , 
         * then we only need to perform "Paste" operation .
         * Performing copy operation in this case may lead to stack over flow
         * due to infinite recursion calls .
         */
        if(length == copy)
        {
            // Paste "copy" number of A's .
            return 1 + helper(length + copy , copy) ;
        }
        else
        {
            return 1 + min(helper(length , length) , helper(length + copy , copy)) ;
        }
    }
    /* If length of current number of A's does not divides the desired number 
     * of A's then , we only need to perform paste operation as copying the 
     * current number of A's won't take us to the desired result .
     */
    return 1 + helper(length + copy , copy) ;
    
}
int Solution :: minSteps(int n)
{
    // Base case .
    if(n == 1)return 0 ;
    this->n = n ;
    int length = 2 ;
    int copy = 1 ;
    return 2 + helper(length , copy) ;
}
