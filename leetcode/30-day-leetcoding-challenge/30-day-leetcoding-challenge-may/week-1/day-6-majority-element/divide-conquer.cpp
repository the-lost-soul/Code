class Solution {
public:
    int majorityElement(vector<int>& nums) ;
    int majority(vector<int>& nums , int left , int right) ;
};

int Solution :: majorityElement(vector<int>& nums)
{
    return majority(nums , 0 , nums.size() - 1) ;
}
int Solution :: majority(vector<int>& nums , int left , int right)
{
    if(right == left)
        return nums[left] ;
    int mid = left + (right - left)/2 ;
    int lm = majority(nums , left , mid) ;
    int rm = majority(nums , mid + 1 , right) ;
    if(lm == rm)
        return lm ;
    return count(nums.begin() + left , nums.begin() + right + 1 , lm) >
            count(nums.begin() + left , nums.begin() + right + 1 , rm) ? lm : rm ;
}
