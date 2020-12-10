class Solution {
public:
    bool kLengthApart(vector<int>& nums, int k) ;
};

bool Solution :: kLengthApart(vector<int>& nums , int k)
{
    vector<int>ind ;
    for(int i = 0 ; i < nums.size() ; i++)
    {
        if(nums[i] == 1)
            ind.push_back(i) ;
    }
    
    int i = 0 ;
    while(i + 1 < ind.size())
    {
        int curr = ind[i] ;
        int next = ind[i + 1] ;
        if(next - curr - 1 < k)
            return false ;
        i++ ;
    }
    return true ;
}
