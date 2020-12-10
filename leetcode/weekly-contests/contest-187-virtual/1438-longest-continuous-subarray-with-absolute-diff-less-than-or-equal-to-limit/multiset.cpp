class Solution {
public:
    int longestSubarray(vector<int>& nums, int limit) ;
};

int Solution :: longestSubarray(vector<int>& nums , int limit)
{
    multiset<int>hash ;
    int j = 0 , ans = INT_MIN ;
    for(int i = 0 ; i < nums.size() ; i++)
    {
        hash.insert(nums[i]) ;
        int maxEle = *(hash.rbegin()) , minEle = *(hash.begin()) ;
        if(maxEle - minEle > limit)
        {
            hash.erase(hash.find(nums[j])) ;
            j++ ;
        }
        ans = max(ans , i - j + 1) ;
    }
    return ans ;
}
