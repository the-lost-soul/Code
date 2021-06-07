class Solution {
public:
    int minOperations(int n) ;
};

int Solution :: minOperations(int n)
{
    int mid ;
    if(n%2 == 1)mid = 2*(n/2) + 1 ;
    else mid = n ;
    
    int operations = 0 ;
    for(int i = 0 ; i < n/2 ; i++)
    {
        operations += (mid - 2*i - 1) ;
        
    }
    return operations ;
}
