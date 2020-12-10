class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) ;
};

vector<int> Solution :: productExceptSelf(vector<int>& nums)
{
    vector<int>ans = nums ;
    int len = ans.size() ;
    ans[0] = 1 ;
    for(int i = 1 ; i < len ; i++)
    {
        ans[i] = ans[i - 1]*nums[i - 1] ;
    }
    int val = nums[len - 1] ;
    for(int i = len - 2 ; i >= 0 ; i--)
    {
        ans[i] *= val ;
        val *= nums[i] ;
    }
    
    return ans ;
}
