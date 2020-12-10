class Solution {
public:
    int bitwiseComplement(int N) ;
};

int Solution :: bitwiseComplement(int N)
{
    if(N == 0)
        return 1 ;
    int num = N ;
    int ones = 0 ;
    // Get the number with all bits 1 .
    while(num != 0)
    {
        ones = 2*ones + 1 ;
        num /= 2 ;
    }

    // Doing XOR of given number with all 1's gives the complement .
    return N ^ ones ;
}
