class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums)
    {
        sort(begin(nums) , end(nums)) ;
        vector<vector<int>> ans ;
        for(int i = 0 ; i < nums.size() ; i++)
        {
            int target = -nums[i] ;
            int left = i + 1 ;
            int right = nums.size() - 1 ;
            while(left < right)
            {
                int sum = nums[left] + nums[right] ;
                if(sum > target)
                    right-- ;
                else if(sum < target)
                    left++ ;
                else
                {
                    vector<int>triplet = {nums[i] , nums[left] , nums[right]} ;
                    ans.push_back(triplet) ;
                    while(left < right and nums[left] == triplet[1])
                        left++ ;
                    while(left < right and nums[right] == triplet[2])
                        right-- ;
                }
            }

            while(i + 1 < nums.size() and nums[i + 1] == nums[i])
                i++ ;
        }
        return ans ;
    }
};
