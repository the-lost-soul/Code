class Solution {
public:
    int movesToMakeZigzag(vector<int>& nums) ;
} ;


int Solution :: movesToMakeZigzag(vector<int>& nums)
{
    int len = nums.size() ;
    int even = 0 , odd = 0 ;
    // Make elements at odd indices smaller .
    for(int i = 1 ; i < len ; i += 2)
    {
        if(i == len -1)
        {
            if(nums[i] >= nums[i-1])odd += nums[i] - nums[i-1] + 1 ;
        }
        else
        {
            if(nums[i] >= nums[i+1] or nums[i] >= nums[i-1])
                odd += nums[i] - min(nums[i+1] , nums[i-1]) + 1 ;
        }
    }
    
    // Make elements add even indices smaller
    for(int i = 0 ; i < len ; i += 2)
    {
        if(i == 0)
        {
            if(nums[i] >= nums[i+1])even += nums[i] - nums[i+1] + 1 ;
        }
        else if(i == len-1)
        {
            if(nums[i] >= nums[i-1])
            {
                even += nums[i] - nums[i-1] + 1 ;
            }
        }
        else
        {
            if(nums[i] >= nums[i-1] or nums[i] >= nums[i+1])
            {
                even += nums[i] - min(nums[i-1] , nums[i+1]) + 1 ;
            }
        }
    }
    return min(even , odd) ;
}
