class Solution {
public:
    int majorityElement(vector<int>& nums) ;
};

int Solution :: majorityElement(vector<int>& nums)
{
    unordered_map<int , int>hash ;
    for(auto ch : nums)
        hash[ch]++ ;
    for(auto details : hash)
        if(details.second > nums.size()/2)
            return details.first ;
    return -1 ;
}
