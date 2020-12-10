class Solution {
public:
    void rotate(vector<int>& nums, int k) ;
};

/* Here , we use an extra array in which we place every element of
 * the original array to its correct position at "temp" array .
 * The number at index i in original array is placed at index (i + k) .
 * Then , we copy the new array to the original one .
 */
void Solution :: rotate(vector<int> & nums , int k)
{
    vector<int>temp(nums.size()) ;
    for(int i = 0 ; i < nums.size() ; i++)
    {
        temp[(i + k) % nums.size()] = nums[i] ;
    }
    
    for(int i = 0 ; i < nums.size() ; i++)
    {
        nums[i] = temp[i] ;
    }
}
