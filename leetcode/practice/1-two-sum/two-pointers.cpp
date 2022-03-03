class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target)
    {
        unordered_map<int , vector<int>> hash ;
        for(int i = 0 ; i < nums.size() ; i++)
            hash[nums[i]].push_back(i) ;

        int left , right ; 
        for(int i = 0 ; i < nums.size() ; i++)
        {
            int first = nums[i] ;
            int second = target - nums[i] ;
            if(hash.find(second) != hash.end())
            {
                if(first != second)
                {
                    left = i ;
                    right = hash[second][0] ;
                    break ;
                }
                if(first == second and hash[second].size() > 1)
                {
                    left = hash[second][0] ;
                    right = hash[second][1] ;
                    break ;
                }
            }
        }
        return {left , right} ;
    }
};

