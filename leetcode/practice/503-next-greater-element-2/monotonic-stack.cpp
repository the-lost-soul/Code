class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums)
    {
        stack<int>stk ;
        for(int i = nums.size() - 1 ; i >= 0 ; i--)
            stk.push(i) ;

        vector<int>next_great(nums.size() , -1) ;
        for(int i = nums.size() - 1 ; i >= 0 ; i--)
        {
            while(!stk.empty() and nums[i] >= nums[stk.top()])
                stk.pop() ;
            next_great[i] = stk.empty() ? -1 : nums[stk.top()] ;
            stk.push(i) ;
        }
        return next_great ;

        
    }
};
