class Solution 
{
    int sum = 0 ;
    public:
        int maxSumDivThree(vector<int>& nums) ;
        void helper(vector<int>& nums , int currSum , int i) ;
};

void Solution :: helper(vector<int>& nums , int currSum , int i)
{
    if(i >= nums.size())
    {
        if(currSum%3 == 0)
            sum = max(sum , currSum) ;
        return ;
    }
    
    helper(nums , currSum + nums[i] , i + 1) ;
    helper(nums , currSum , i + 1) ;
}
int Solution :: maxSumDivThree(vector<int>& nums)
{
    helper(nums , 0 , 0) ;
    return sum ;
}
