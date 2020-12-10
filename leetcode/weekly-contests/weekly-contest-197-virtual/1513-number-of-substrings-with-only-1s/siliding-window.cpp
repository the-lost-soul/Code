class Solution {
    const int mod = 1e9 + 7 ;
public:
    int numSub(string s) ;
};

int Solution :: numSub(string s)
{
    long ans = 0 , i = 0 , start = 0 ;
    while(i < s.length())
    {
        while(i < s.length() and s[i] == '0')i++ ;
        start = i ;
        
        while(i < s.length() and s[i] == '1')i++ ;
        
        ans = ans%mod + (((i - start)%mod)*((i - start + 1)%mod))/2 ;
    }
    return ans ;
}
