class Solution {
public:
    int jump(vector<int>& nums)
    {
        vector<int>jumps(nums.size() , INT_MAX) ;
        vector<bool>reachable(nums.size() , false) ;
        jumps[nums.size() - 1] = 0 ;
        reachable[nums.size() - 1] = true ;

        for(int i = nums.size() - 2 ; i >= 0 ; i--)
        {
            int steps = nums[i] ;
            for(int j = 1 ; j <= steps ; j++)
            {
                int ind = i + j ;
                // If the step from ith position is greater
                // than size of vector then break .
                if(ind >= nums.size())break ;
                // If end is reachable from i --> ind ....--->>> end .
                if(reachable[ind])
                    jumps[i] = jumps[i] > jumps[ind] ? jumps[ind] + 1 : jumps[i] ;
            }
            if(nums[i] == 0 or jumps[i] == INT_MAX)
                jumps[i] = 0 ;
            else
                reachable[i] = true ;
        }

        return jumps[0] ;
    }
};
