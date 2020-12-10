class Solution {
public:
    bool isPerfectSquare(int num) ;
};

bool Solution :: isPerfectSquare(int num)
{
    for(unsigned long i = 1 ; i*i <= num ; i++)
    {
        if(i*i == num)
            return true ;
    }
    return false ;
}
