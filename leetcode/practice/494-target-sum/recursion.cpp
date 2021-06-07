class Solution {
public :
    int count ;
    int findTargetSumWays(vector<int>& nums, int target) ;
    void helper(int currSum , vector<int>& nums , int i , int target) ;
};

void Solution :: helper(int currSum , vector<int>& nums , int i , int target)
{
    if(target == currSum and i == nums.size())
    {
        count++ ;
    }
    if(i >= nums.size())
        return ;
    
    currSum += nums[i] ;
    helper(currSum , nums , i + 1 , target) ;
    currSum -= 2*nums[i] ;
    helper(currSum , nums , i + 1 , target) ;
}
int Solution :: findTargetSumWays(vector<int>& nums , int target)
{
    count = 0 ;
    int sum = nums[0] ;
    helper(sum , nums , 1, target) ;
    sum = -nums[0] ;
    helper(sum , nums , 1 , target) ;
    return count ;
}
