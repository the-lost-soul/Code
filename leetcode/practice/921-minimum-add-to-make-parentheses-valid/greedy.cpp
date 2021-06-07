class Solution {
public:
    int minAddToMakeValid(string str) ;
};

int Solution :: minAddToMakeValid(string str)
{
    int open = 0 ;
    int close = 0 ;
    for(auto ch : str)
    {
        if(ch == '(')open++ ;
        else
        {
            if(open == 0)
            {
                close++ ;
            }
            else open-- ;
        }
    }
    return open + close ;
}
