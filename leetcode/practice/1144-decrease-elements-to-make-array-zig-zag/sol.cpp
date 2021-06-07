class Solution {
public:
    int movesToMakeZigzag(vector<int>& nums) ;
} ;

int costUsingEven(vector<int> nums)
{
    int len = nums.size() ;
    int moves = 0 ;
    for(int i = 0 ; i < len-1 ; i++)
    {
        if(i%2 == 0)
        {
            if(nums[i] <= nums[i+1])
            {
                moves = moves + nums[i+1] - nums[i] + 1 ;
                nums[i+1] = nums[i] - 1 ;
            }
        }
        else
        {
            if(nums[i] >= nums[i+1])
            {
                moves = moves + nums[i] - nums[i+1] + 1 ;
                nums[i] = nums[i+1] - 1 ;
            }
        }
    }
    return moves ;
}

int costUsingOdd(vector<int> nums)
{
    int len = nums.size() ;
    int moves = 0 ;
    for(int i = 0 ; i < len-1 ; i++)
    {
        if(i%2 == 0)
        {
            if(nums[i] >= nums[i+1])
            {
                moves = moves + nums[i] - nums[i+1] + 1 ;
                nums[i] = nums[i+1] - 1 ;
            }
        }
        else
        {
            if(nums[i] <= nums[i+1])
            {
                moves = moves + nums[i+1] - nums[i] + 1 ;
                nums[i+1] = nums[i] - 1 ;
            }
        }
    }
    return moves ;
}
int Solution :: movesToMakeZigzag(vector<int>& nums)
{
    return min(costUsingOdd(nums) , costUsingEven(nums)) ;
}
