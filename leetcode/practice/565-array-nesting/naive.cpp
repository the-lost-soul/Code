class Solution {
public :
    int arrayNesting(vector<int>& nums) ;
};

int Solution :: arrayNesting(vector<int>& nums)
{
    int len = nums.size() ;
    int res = INT_MIN ;
    for(int i = 0 ; i < len ; i++)
    {
        int count = 0 ;
        int ele = nums[i] ;
        count++ ;
        ele = nums[ele] ;
        while(ele != nums[i])
        {
            count++ ;
            ele = nums[ele] ;
        }
        res = max(res , count) ;
    }
    return res ;
}
