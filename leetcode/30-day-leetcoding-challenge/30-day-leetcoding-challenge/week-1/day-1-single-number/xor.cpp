class Solution {
public:
    int singleNumber(vector<int>& nums) ;
};

int Solution :: singleNumber(vector<int>& nums)
{
    int numXOR = 0 ;
    for(auto ele : nums)
        numXOR ^= ele ;
    return numXOR ;
}
