class Solution {
public:
    int maximumProduct(vector<int>& nums) ;
};

int Solution :: maximumProduct(vector<int>& nums)
{
    int num1 , num2 , num3 ;
    num1 = num2 = num3 = INT_MIN ;
    int min1 = INT_MAX , min2 = INT_MAX ;
    
    int ind = 0 , len = size(nums) ;
    while(ind < len)
    {
        if(nums[ind] >= num1)
        {
            num3 = num2 ;
            num2 = num1 ;
            num1 = nums[ind] ;
        }
        else if(nums[ind] >= num2)
        {
            num3 = num2 ;
            num2 = nums[ind] ;
        }
        else if(nums[ind] >= num3)
        {
            num3 = nums[ind] ;
        }
        if(nums[ind] <= min1)
        {
            min2 = min1 ;
            min1 =nums[ind] ;
        }
        else if(nums[ind] <= min2)
        {
            min2 = nums[ind] ;
        }
        
        ind++ ;
    }
    return max(num1*num2*num3 , min1*min2*num1) ;
}   
