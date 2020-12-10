class Solution {

public:
    int constrainedSubsetSum(vector<int>& nums, int k) ;
};

int Solution :: constrainedSubsetSum(vector<int>& nums , int k)
{
    vector<int>dp(nums.size() , 0) ;
    multiset<int> mySet ;
    for(int i = 0 ; i < nums.size() ; i++)
    {
        int ele = 0 ;
        if(!mySet.empty()) ele = *(mySet.rbegin()) ;
        dp[i] = max(nums[i] , nums[i] + ele) ;
        mySet.insert(dp[i]) ;
        if(i >= k)
        {
            auto itr = mySet.find(dp[i - k]) ;
            mySet.erase(itr) ;
        }
    }
    return *max_element(dp.begin() , dp.end()) ;
}
