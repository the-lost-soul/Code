class Solution {
public:
    int majorityElement(vector<int>& nums) ;
};
/* The trick here is that since solution exists
 * so we find out for every ith bit whether there
 * are vector elements whose ith bit is also set .
 * If the count of set bits is greater than size/2
 * then we can say that ith bit is also set in the
 * majority element .
 */
int Solution :: majorityElement(vector<int>& nums)
{
    int len = nums.size() ;
    int num = 0 ;
    for(int i = 0 ; i < 32 ; i++)
    {
        int countBits = 0 ;
        for(int j = 0 ; j < len ; j++)
        {
            if((1<<i) & nums[j])countBits++ ;
        }
        if(countBits > len/2)
        {
            num += 1<<i ;
        }
    }
    return num ;
}
