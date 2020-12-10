class Solution {
public:
    int findDuplicate(vector<int>& nums) ;
};

int Solution :: findDuplicate(vector<int>& nums)
{
    int ans = 0 ;
    for(int i = 0 ; i < nums.size() ; i++)
    {
        if(nums[abs(nums[i])] > 0)
        {
            nums[abs(nums[i])] = -nums[abs(nums[i])] ;
        }
        else 
        {
            ans = abs(nums[i]) ;
            break ;
        }
    }
    return ans ;
}
