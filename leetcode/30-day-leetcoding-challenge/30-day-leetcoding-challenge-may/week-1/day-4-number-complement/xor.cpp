class Solution {
public:
    int findComplement(int num) ;
};

int Solution :: findComplement(int num)
{
    int ans = 0 ;
    while(num > ans)
    {
        ans = ans*2 + 1 ;
    }
    return ans xor num ;
}
