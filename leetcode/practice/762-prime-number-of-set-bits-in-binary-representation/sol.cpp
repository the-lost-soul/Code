class Solution
{
public:
    int countSetBits(int num)
    {
        int bits = 0 ;
        while(num != 0)
        {
            bits += (num & 1) == 1 ;
            num >>= 1 ;
        }
        return bits ;
    }

    int countPrimeSetBits(int left, int right)
    {
        unordered_set<int>primes({2 , 3 , 5 , 7 , 11 , 13 , 17 , 19}) ;

        int ans = 0 ;
        for(int i = left ; i <= right ; i++)
        {
            int setBits = countSetBits(i) ;
            ans += (primes.find(setBits) != primes.end()) ? 1 : 0 ;
        }
        return ans ;
    }
};
