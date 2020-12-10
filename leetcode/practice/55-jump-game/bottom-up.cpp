class Solution {
public:
    bool canJump(vector<int>& nums) ;
 };


bool Solution :: canJump(vector<int>& nums)
{
    vector<int>dp(nums.size() , -1) ;
    dp[nums.size() - 1] = 1 ;
    for(int i = nums.size() - 2 ; i >= 0 ; i--)
    {
        int maxSteps = i + nums[i] > nums.size() - 1 ? nums.size() - 1 : i + nums[i] ;
        for(int j = i + 1 ; j <= maxSteps ; j++)
        {
            if(dp[j] == 1)
            {
                dp[i] = 1 ;
                break ;
            }
        }
    }
    return dp[0] == 1 ;
}
