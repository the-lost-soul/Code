class Solution {
public:
    int findNumbers(vector<int>& nums) ;
};

int Solution :: findNumbers(vector<int>& nums)
{
    int len = nums.size() ;
    int currNum = 0 , digitCount , count = 0 ;
    for(int i = 0 ; i < len ; i++)
    {
        currNum = nums[i] ;
        digitCount = 0 ;
        while(currNum != 0)
        {
            digitCount++ ;
            currNum /= 10 ;
        }
        if(digitCount%2 == 0)count++ ;
    }
    return count ;
}
