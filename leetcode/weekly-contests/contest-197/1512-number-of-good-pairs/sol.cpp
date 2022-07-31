class Solution {
public:
    int numIdenticalPairs(vector<int>& nums) ;
};

int Solution :: numIdenticalPairs(vector<int>& nums)
{
    unordered_map<int , int>hash ;
    for(auto x : nums)
        hash[x]++ ;
    
    int ans = 0 ;
    for(auto p : hash)
    {
        ans += ((p.second)*(p.second - 1))/2 ;
    }
    return ans ;
}
