class Solution {
public:
    bool isPowerOfTwo(int n) ;
};

bool Solution :: isPowerOfTwo(int n)
{
    if(n <= 0)
        return false ;
    
    int setBit = 0 ;
    while(n != 0)
    {
        if(n&1)
        {
            setBit++ ;
        }
        if(setBit > 1)
            return false ;
        n = n >> 1 ;
    }
    return true ;

}
