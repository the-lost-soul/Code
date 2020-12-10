class Solution {
public:
    int clumsy(int N) ;
    int helper(int N) ;
};

int Solution :: clumsy(int N)
{
    if(N <= 2) return N ;
    else if(N <= 4) return N + 3 ;
    
    
    
    return N*(N - 1)/(N - 2) + N - 3 + helper(N - 4) ;
}

int Solution :: helper(int N) 
{
    if(N <= 2) return -N ;
    if(N < 4) return -(N + 3) ;
    
    return -(N*(N - 1)/(N - 2) -( N - 3)) + helper(N - 4) ;
}
