class Solution {
public:
    bool isPossibleDivide(vector<int>& nums, int k) ;
};

bool Solution :: isPossibleDivide(vector<int>& nums , int k)
{
    int len = nums.size() ;
    if(len%k != 0)return false ;
    map<int , int>hash ;
    for(int i = 0 ; i < len ; i++)
    {
        hash[nums[i]]++ ;
    }
    int freq  = 0 ;
    for(auto itr = hash.begin() ; itr != hash.end() ; itr++)
    {
        freq = itr->second ;
        if(freq > 0)
        {
            for(int i = 0 ; i < k ; i++)
            {
                if(hash[i + itr->first] < freq)return false ;
                else hash[i + itr->first] -= freq ;
            }
        }
    }
    return true ;
    
}
