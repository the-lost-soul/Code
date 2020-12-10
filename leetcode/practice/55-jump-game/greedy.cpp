class Solution {
public:
    bool canJump(vector<int>& nums) ;
};

bool Solution :: canJump(vector<int>& nums)
{
    int lastPos = nums.size() - 1 ;
    for(int i = nums.size() - 2 ; i >= 0 ; i--)
    {
        if(i + nums[i] >= lastPos)
            lastPos = i ;
    }
    return lastPos == 0 ;
}
