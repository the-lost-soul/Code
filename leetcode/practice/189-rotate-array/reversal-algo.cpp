class Solution {
public:
    void rotate(vector<int>& nums, int k) ;
    void reverse(vector<int>&nums , int start , int end) ;
};

void Solution :: reverse(vector<int>&nums , int start , int end)
{
    while(start < end)
    {
        swap(nums[start] , nums[end]) ;
        start ++ ;
        end -- ;
    }
}

void Solution :: rotate(vector<int> & nums , int k)
{
    int length = nums.size() ;
    k %= length ;
    // This way of normalization is wrong , take example of length = 10 
    // and k = 14 , here by doing k -= length , we will get k = 4 , which
    // is correct but take example when k = 24 , here by doing k -= length
    // we will get k = 14 , which is wrong so we can remove this bug using
    // while loop
    if(k >= length)k -= length ;
    reverse(nums , 0 , length - 1) ;
    reverse(nums , 0 , k - 1) ;
    reverse(nums , k , length - 1) ;
    
}
