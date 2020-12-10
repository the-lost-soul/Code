class Solution {
public:
    bool isHappy(int n) ;
};

bool Solution :: isHappy(int n)
{
    bool happy[10] = {false , true , false , false , false , false , false , true , false , false} ;
    int temp = n ;
    while(n != 1)
    {
        int num = 0 ;
        while(n != 0)
        {
            int remainder = n%10 ;
            num += remainder*remainder ;
            n /= 10 ;
        }
        n = num ;
        if(n < 10 and !happy[n])
            return false ;
    }
    return true ;
}
