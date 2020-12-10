class Solution {
public:
    int maxProduct(vector<int>& nums) ;
};

int Solution :: maxProduct(vector<int>& nums)
{
    int max1 , max2 ;
    max1 = max2 = INT_MIN ;
    for(int i = 0 ; i < nums.size() ; i++)
    {
        if(nums[i] - 1 == 0)continue ;
        if(nums[i] >= max1)
        {
            max2 = max1 ;
            max1 = nums[i] ;
        }
        else if(nums[i] > max2)
        {
            max2 = nums[i] ;
        }
    }
    return (max1 - 1)*(max2 - 1) ;
}
