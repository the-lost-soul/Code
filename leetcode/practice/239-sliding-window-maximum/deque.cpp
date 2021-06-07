class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) ;
};

vector<int> Solution :: maxSlidingWindow(vector<int>& nums , int k)
{
    deque<int>dq ;
    dq.push_front(nums[0]) ;
    for(int i = 1 ; i < k ; i++)
    {
        /* Delete all element from deque which are less than 
         * current element as they won't be of any use for 
         * next windows and then push the current element of
         * present window .
         */
        while(dq.front() < nums[i])
        {
            dq.pop_front() ;
            if(dq.empty())break ;
        }
        dq.push_front(nums[i]) ;
    }
    vector<int>ans ;
    ans.push_back(dq.back()) ;
    for(int i = k ; i < nums.size() ; i++)
    {
        int notNeeded = nums[i - k] ;
        int dqEle = dq.back() ;
        /* If the max element present in deque is equal to
         * the element which we don't need in current window .
         * Simply delete it .
         */
        if(dqEle == notNeeded)
        {
            dq.pop_back() ;
        }
        /* Delete all elements from deque which are less than last 
         * element of current window as they won't be of any use 
         * for next windows .
         */
        while(dq.front() < nums[i])
        {
            dq.pop_front() ;
            if(dq.empty())break ;
        }
        // The answer for current window will either be last element of
        // current window or max element present in deque .
        ans.push_back(max(nums[i] , !dq.empty() ? dq.back() : INT_MIN)) ;
        dq.push_front(nums[i]) ;
    }
    return ans ;
}
