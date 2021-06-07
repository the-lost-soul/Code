class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) ;
};

int Solution :: singleNonDuplicate(vector<int>& nums)
{
    int n = nums.size() ;
    int left = 0 , right = n - 1 ;
    while(left <= right)
    {
        int mid = left + (right - left)/2 ;
        if((mid - 1 >= 0 and nums[mid] == nums[mid - 1]))
        {
            if(mid%2 == 0)right = mid - 1 ;
            else left = mid + 1 ;
        }
        else if(mid + 1 < n and nums[mid] == nums[mid + 1])
        {
            if(mid%2 == 0)left = mid + 1 ;
            else right = mid - 1 ;
        }
        else return nums[mid] ;
    }
    return nums[left] ;
}
