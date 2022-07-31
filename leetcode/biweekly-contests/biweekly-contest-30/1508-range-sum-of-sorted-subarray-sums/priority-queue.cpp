class Solution {
    const int mod = 1e9 + 7 ;
public:
    int rangeSum(vector<int>& nums, int n, int left, int right) ;
};

int Solution :: rangeSum(vector<int>& nums , int n , int left , int right)
{
    priority_queue<int> subarray ;
    int currsum ;
    for(int i = 0 ; i < nums.size() ; i++)
    {
        currsum = 0 ;
        for(int j = i ; j < nums.size() ; j++)
        {
            currsum += nums[j] ;
            if(subarray.size() < right)
            {
                subarray.push(currsum) ;
            }
            else if(subarray.top() > currsum)
            {
                subarray.pop() ;
                subarray.push(currsum) ;
            }  
        }
    }
    
    int ele_count = right - left + 1 , ans = 0 ;
    while(ele_count-- > 0)
    {
        ans = ans%mod + subarray.top() ;
        ans %= mod ;
        subarray.pop() ;
    }
    
    return ans ;
}
