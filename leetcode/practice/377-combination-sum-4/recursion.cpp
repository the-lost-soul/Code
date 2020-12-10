class Solution {
public:
    int combinationSum4(vector<int>& nums, int target) ;
};

int Solution :: combinationSum4(vector<int>& nums , int target)
{
    if(target == 0)
        return 1 ;
    int res = 0 ;
    for(int i = 0 ; i < size(nums) ; i++)
    {
        if(nums[i] <= target)
        {
            res += combinationSum4(nums , target - nums[i]) ;
        }
    }
    return res ;
}
