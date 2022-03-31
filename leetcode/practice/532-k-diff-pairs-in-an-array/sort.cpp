// unordered_set uses std::hash for computing hash values for its keys
// and there is no standard specialization of std::hash for std::pair in
// c++ library .
struct pair_hash
{
    template <class T1, class T2>
    std::size_t operator () (std::pair<T1, T2> const &pair) const
    {
        std::size_t h1 = std::hash<T1>()(pair.first);
        std::size_t h2 = std::hash<T2>()(pair.second);
 
        return h1 ^ h2;
    }
};

class Solution {
public:
    int findPairs(vector<int>& nums, int k)
    {
        sort(nums.begin() , nums.end() , greater<int>()) ;
        int j = 1 , n = nums.size() ;
        unordered_set<pair<int , int> , pair_hash> hash ;
        for(int i = 0 ; i < n ; i++)
        {
            // edge case .
            if(i == j)
                j = i + 1 ;

            int lhs = nums[i] ;
            while(j < n)
            {
                int rhs = k + nums[j] ;
                if(rhs > lhs)
                    j++ ;
                else break ;
            }

            while(j < n)
            {
                int rhs = k + nums[j] ;
                if(lhs == rhs)
                {
                    if(hash.find({nums[i] , nums[j]}) == hash.end())
                        hash.insert({nums[i] , nums[j]}) ;
                    j++ ;
                }
                else break ;
            }
        }
        return hash.size() ;
    }
};
