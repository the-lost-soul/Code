class Solution {
public:
    int minMoves(vector<int>& nums) ;
};

int Solution :: minMoves(vector<int>& nums)
{
    long minEle = *min_element(nums.begin() , nums.end()) ;
    int len = nums.size() ;
    long sum = accumulate(begin(nums) , end(nums) , 0L) ;
    return sum - minEle*len ;
}
