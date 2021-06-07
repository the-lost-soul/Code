class Solution {
public :
    vector<vector<int>>memo ;
    int findTargetSumWays(vector<int>& nums , int target) ;
    int helper(int currSum , vector<int>& nums , int i , int target) ;
} ;


int Solution :: helper(int currSum , vector<int>& nums , int i , int target)
{
    if(i == nums.size())
    {
        if(target == currSum)
            return 1 ;
        else
            return 0 ;
    }
    if(memo[i][currSum + 1000] != INT_MIN)
        return memo[i][currSum + 1000] ;
    int add = helper(currSum + nums[i] , nums , i + 1 , target) ;
    int subtract = helper(currSum - nums[i] , nums , i + 1 , target) ;
    memo[i][currSum + 1000] = add + subtract ;
    return memo[i][currSum + 1000] ;
}
int Solution :: findTargetSumWays(vector<int>& nums , int target)
{
    int sum = 0 ;
    memo = vector<vector<int>>(nums.size() , vector<int>(2001 , INT_MIN)) ;
    return helper(sum , nums , 0 , target) ;
}
