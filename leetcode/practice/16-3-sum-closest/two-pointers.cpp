class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target)
    {
        sort(begin(nums) , end(nums)) ;
        int sum = nums[0] + nums[1] + nums[2] ;
        int prev_dist = abs(target - sum) ;

        for(int first = 0 ; first < nums.size() - 2 ; first++)
        {
            int second = first + 1 ;
            int third = nums.size() - 1 ;
            while(second < third)
            {
                int triples = nums[first] + nums[second] + nums[third] ;
                int dist = abs(target - triples) ;
                if(prev_dist > dist)
                {
                    prev_dist = dist ;
                    sum = triples ;
                }

                if(triples > target) third-- ;
                else if(triples < target) second++ ;
                else return target ;
            }
        }
        return sum ;
    }
};
