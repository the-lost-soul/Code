class Solution {
public:
    int majorityElement(vector<int>& nums) ;
};
int Solution :: majorityElement(vector<int>& nums)
{
    int len = nums.size() ;
    int candidate = -1 ;
    int count = 0 ;
    for(int i = 0 ; i < len ; i++)
    {
        if(count == 0)
        {
            count += 1 ;
            candidate = nums[i] ;
        }
        else
        {
            if(candidate == nums[i])count++ ;
            else count-- ;
        }
    }
    return candidate ;
}
