class Solution
{
public:
    bool isMonotonic(vector<int>& nums)
    {
        bool increasing = true ;
        
        int i = 0 , len = nums.size() ;
        while(i + 1 < len and nums[i] <= nums[i + 1])
            i++ ;
        if(i == len - 1)
            return true ;
        i = 0 ;
        while(i + 1 < len and nums[i] >= nums[i + 1])
            i++ ;
        if(i == len - 1)
            return true ;
        return false ;
    }
};
