class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2)
    {
        unordered_map<int , int>hash ;
        for(int i = 0 ; i < nums2.size() ; i++)
            hash[nums2[i]] = i ;

        vector<int> next_greater(nums2.size()) ;
        stack<int>monotonic_stack ;
        for(int i = nums2.size() - 1 ; i >= 0 ; i--)
        {
            while(!monotonic_stack.empty() and nums2[i] >= monotonic_stack.top())
                monotonic_stack.pop() ;

            next_greater[i] = monotonic_stack.empty() ? -1 : monotonic_stack.top() ;
            monotonic_stack.push(nums2[i]) ;
        }

        vector<int> ans ;
        for(auto ele : nums1)
            ans.push_back(next_greater[hash[ele]]) ;

        return ans ;
    }
};
