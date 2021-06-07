class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) ;
};

vector<int> Solution :: twoSum(vector<int>& numbers , int target)
{
    int left = 0 , right = numbers.size() - 1 ;
    int sum = 0 ;
    
    while(left < right)
    {
        sum = numbers[left] + numbers[right] ;
        if(sum == target)
        {
            vector<int>arr{left + 1 , right + 1} ;
            return arr ;
        }
        else if(sum > target)right-- ;
        else left++ ;
    } 
    
    // Return an empty vector .
    return {} ;
}
