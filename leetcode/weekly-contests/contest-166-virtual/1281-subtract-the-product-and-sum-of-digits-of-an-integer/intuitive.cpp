class Solution {
public:
    int subtractProductAndSum(int n) ;
};

int Solution :: subtractProductAndSum(int n)
{
    // Get product and sum 
    int prod = 1 , sum = 0 , rem = 0 ;
    while(n != 0)
    {
        rem = n%10 ;
        sum += rem ;
        prod *= rem ;
        n /= 10 ;
    }
    return prod - sum ;
    
}
