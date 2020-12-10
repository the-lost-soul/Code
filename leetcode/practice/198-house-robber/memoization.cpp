class Solution {
public:
    int rob(vector<int>& nums) ;
};
 /* The DP definition is -----
  * cost[i] = max {
  *                  (cost[i] + max{cost[0]....cost[i-2]})-->If we rob current house , 
  *                  
  *                  cost[i - 1] -->If we don't rob current house , we are not robbing
  *                                  current house because it is not maximizing the profit 
  *                                  which we got robbing the house just before it .
  *             }
  */

int Solution :: rob(vector<int>& nums)
{
    int len = nums.size() ;
    // Base case .
    if(len == 0)return 0 ;
    // Stores the maximum money robbed till ith house .
    int cost[len] = {} ;
    // For first house , max money will be the amount present
    // in that house , or it may be zero if current house has
    // negative money .
    cost[0] = max(0 , nums[0]) ;
    if(len == 1)return cost[0] ;
    // if(len == 2)return max(nums[len - 1] , nums[len - 2]) ;
    /* For next house , we have option either we rob that house if
     * the money is greater than the earlier robbed house , else we
     * don't rob it .
     */
    cost[1] = max(cost[0] , nums[1]) ;
    for(int i = 2 ; i < len ; i++)
    {
        /* If we can rob current house , then money we will be having
         * is nums[i] + cost[i - 2] , else we don't rob it and move ahead .
         * We can rob current house only when it can maximixe our profit
         * as compared to the house we robbed just before(i.e it's adjacent) .
         */
        cost[i] = max(cost[i - 1] , nums[i] + cost[i - 2]) ;
    }
    return cost[len - 1] ;
}
