class Solution {
public:
    const int mod = 1e9 + 7 ;
    int numOfWays(int n) ;
    int helper(int n , char tile1 , char tile2 , char tile3) ;
};

int Solution :: helper(int n , char tile1 , char tile2 , char tile3)
{
    if(n == 0) return 1 ;
    string colors = "RGY" ;
    long res = 0 ;
    for(auto color1 : colors)
    {
        if(color1 != tile1)
        {
            for(auto color2 : colors)
            {
                if(color2 != tile2 and color1 != color2)
                {
                    for(auto color3 : colors)
                    {
                        if(color3 != tile3 and color3 != color2)
                        {
                            res += helper(n - 1 , color1 , color2 , color3)%mod ;
                        }
                    }
                }
            }
        }
    }
    return res%mod ;
}

int Solution :: numOfWays(int n)
{
    return helper(n , '\0' , '\0' , '\0') ;
}
