class Solution {
public:
    int maximumProduct(vector<int>& nums) ;
};

int Solution :: maximumProduct(vector<int>& nums)
{
    sort(begin(nums) , end(nums)) ;
    
    int len = size(nums) ;
    // If first two are negative
    int ans1 = nums[0]*nums[1]*nums[len - 1] ;
    // If last three are positive .
    int ans2 = nums[len - 1]*nums[len - 2]*nums[len - 3] ;
    // If all numbers are negative .
    int ans3 = nums[0]*nums[1]*nums[2] ;
    return max(ans1 , max(ans3 , ans2)) ; 
}   
