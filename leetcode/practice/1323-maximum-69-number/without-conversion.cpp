class Solution {
public:
    int maximum69Number (int num) ;
};

int Solution :: maximum69Number(int num)
{
    int temp = num ;
    int ind = -1 , i = 0 ;
    while(temp != 0)
    {
        ind = temp%10 == 6 ? i : ind ;
        temp /= 10 ;   
        i++ ;   
    }
    return num + 3*(ind != -1 ? pow(10 , ind) : 0) ;
}
