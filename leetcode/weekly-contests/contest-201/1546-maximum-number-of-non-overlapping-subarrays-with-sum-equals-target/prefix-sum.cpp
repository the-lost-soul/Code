class Solution
{
public:
    int maxNonOverlapping(vector<int>& nums, int target)
    {
        unordered_map<int , int>hash ;
        hash[0] = -1 ;
        int prefixSum = 0 , index = -1 , res = 0 ;
        for(int i = 0 ; i < nums.size() ; i++)
        {
            prefixSum += nums[i] ;
            int remain = prefixSum - target ;
            if(hash.find(remain) != hash.end())
            {
                if(index <= hash[remain])
                {
                    res++ ;
                    index = i ;
                }
            }
            hash[prefixSum] = i ;
        }
        return res ;
    }
};

