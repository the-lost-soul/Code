class Solution {
public:
    int triangleNumber(vector<int>& nums) ;
};

int Solution :: triangleNumber(vector<int>& nums)
{
    if(nums.size() == 1 or nums.size() == 2)
        return 0 ;
    sort(begin(nums) , end(nums)) ;
    int valid = 0 ;
    for(int i = 0 ; i < size(nums) - 2  ; i++)
    {
        int left = i + 2 ;
        for(int j = i + 1 ; j < nums.size() - 1 and nums[i] != 0 ; j++)
        {
            int right = size(nums) - 1 ;
            while(left <= right)
            {
                int mid = (left + right)/2 ;
                if(nums[i] + nums[j] <= nums[mid])
                {
                    right = mid - 1 ;
                }
                else
                {
                    left = mid + 1 ;
                }  
            }
            valid += (left - j - 1) ;   
        }
    }
    return valid ;
}
