class Solution {
public:
    int maxScore(string s) ;
};

int Solution :: maxScore(string s)
{
    int ones = count(s.begin() , s.end() , '1') ;
    int sum = 0 , zeroes = 0 ;
    for(int i = 0 ; i < s.length() - 1 ; i++)
    {
        if(s[i] == '0')
        {
            zeroes++ ;
            sum = max(sum , ones + zeroes) ;   
        }
        else
        {
            ones-- ;
            sum = max(sum , ones + zeroes) ;
        }
    }
    return sum ;
}
