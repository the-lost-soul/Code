class Solution
{
public:
    int monotoneIncreasingDigits(int n)
    {
        string num = to_string(n) ;
        int divider = num.size() ;
        for(int i = num.size() - 1 ; i > 0 ; i--)
        {
            if(num[i - 1] > num[i])
            {
                num[i - 1] = num[i - 1] - 1 ;
                divider = i ;
            }
        }

        for(int i = divider ; i < num.size() ; i++)
            num[i] = '9' ;

        return stoi(num) ;
    }
};
