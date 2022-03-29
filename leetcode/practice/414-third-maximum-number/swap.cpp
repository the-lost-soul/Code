class Solution {
public:
    int thirdMax(vector<int>& nums)
    {
        // base cases .
        if(nums.size() == 1)
            return nums[0] ;
        if(nums.size() == 2)
            return max(nums[0] , nums[1]) ;

        long max1 , max2 , max3 ;
        max1 = max2 = max3 = LONG_MIN ;

        for(auto ele : nums)
        {
            if(ele == max1 or ele == max2 or ele == max3)continue ;
            if(ele >= max1)
            {
                max3 = max2 ; 
                max2 = max1 ; 
                max1 = ele ;
            }
            else if(ele > max2)
            {
                max3 = max2 ;
                max2 = ele ;
            }
            else if(ele > max3)
            {
                max3 = ele ;
            }
        }
        return max3 != LONG_MIN ? (int)max3 : (max1 != LONG_MIN ? (int)max1 : (int)max2) ;
    }
};
