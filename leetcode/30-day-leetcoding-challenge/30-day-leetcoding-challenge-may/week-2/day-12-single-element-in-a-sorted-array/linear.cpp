class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) ;
};

int Solution :: singleNonDuplicate(vector<int>& nums)
{
    int n = nums.size() , i = 0 ;
    while(i < n)
    {
        if((i + 1) < n and nums[i] == nums[i + 1])
        {
            i += 2 ;
        }
        else return nums[i] ;
    }
    return -1 ;
}
