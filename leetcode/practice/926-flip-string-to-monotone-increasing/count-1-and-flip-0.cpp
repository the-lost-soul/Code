class Solution {
public:
    int minFlipsMonoIncr(string str) ;
};

int Solution :: minFlipsMonoIncr(string str)
{
    int len = str.length() , i = 0 ;
    int flip = 0 , count1 = 0 ;
    for(auto ch : str)
    {
        if(count1 == 0 and ch == '0')continue ;
        if(ch == '1')
        {
            count1++ ;
        }
        else flip++ ;
        
        if(count1 < flip)
        {
            flip = count1 ;
        }
    }
    return flip ;
}
