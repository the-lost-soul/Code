class Solution {
public:
    int maxProduct(vector<int>& nums)
    {
        int left = 1 , right = 1 , ans = INT_MIN ;

        for(int i = 0 ; i < nums.size() ; i++)
        {
            // when product becomes 0 , then reset it to 1 .
            left = left == 0 ? 1 : left ;
            right = right == 0 ? 1 : right ;

            // prefix product .
            left *= nums[i] ;
            // suffix product .
            right *= nums[nums.size() - i - 1] ;
            ans = max(ans , max(left , right)) ;
        }
        return ans ;
    }
};
