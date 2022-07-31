class Solution
{
public:
    char findKthBit(int n, int k)
    {
        if(n == 1)
            return '0' ;

        int mid = (pow(2 , n) - 1)/2 + 1 ;
        if(mid == k)
            return '1' ;

        char ans ;
        if(mid < k)
        {
            ans = findKthBit(n - 1 , mid - (k - mid)) ;
            if(ans == '1')
                return '0' ;
            return '1' ;
        }

        if(mid > k)
            ans = findKthBit(n - 1 , k) ;
        return ans ;
    }
};



