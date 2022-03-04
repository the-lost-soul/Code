class Solution {
public:
    int myAtoi(string str)
    {
        int i = 0 , len = str.size() ;
        while(i < len and str[i] == ' ')
            i++ ;

        int sign = 1 ;
        if(i < len)
        {
            if(str[i] == '-')
            {
                sign = -1 ;
                i++ ;
            }
            else if(str[i] == '+')
            {
                sign = 1 ;
                i++ ;
            }
        }
        
        while(i < len and str[i] == '0')
            i++ ;

        string digit = "" ;
        while(i < len and (str[i] >= '0' and str[i] <= '9'))
        {
            digit += str[i] ;
            i++ ;
        }


        i = 0 ;
        int ans = 0 ;
        while(i < digit.size())
        {
            if((ans > INT_MAX/10) or (ans == INT_MAX/10 and (digit[i] - '0' > INT_MAX%10)))
                return sign == 1 ? INT_MAX : INT_MIN ;
            ans = ans*10 + (digit[i] - '0') ;
            i++ ;
        }

        return sign*ans ;
    }
};
