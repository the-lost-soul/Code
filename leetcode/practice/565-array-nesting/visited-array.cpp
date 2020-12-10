class Solution {
public :
    int arrayNesting(vector<int>& nums) ;
};

int Solution :: arrayNesting(vector<int>& nums)
{
    int len = nums.size() ;
    int res = INT_MIN ;
    vector<bool>visited(len , false) ;
    for(int i = 0 ; i < len ; i++)
    {
        if(!visited[nums[i]])
        {
            int count = 0 ;
            int ele = nums[i] ;
            visited[ele] = true ;
            count++ ;
            ele = nums[ele] ;
            while(ele != nums[i])
            {
                count++ ;
                visited[ele] = true ;
                ele = nums[ele] ;
            }
            res = max(res , count) ;
        }
    }
    return res ;
}
