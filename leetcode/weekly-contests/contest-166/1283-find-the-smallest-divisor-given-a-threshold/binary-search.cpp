class Solution {
public:
    int smallestDivisor(vector<int>& nums, int threshold) ;
    int findThreshold(vector<int>& nums , int divisor) ;
};

int Solution :: findThreshold(vector<int>& nums , int divisor)
{
    int len = nums.size() ;
    int sum = 0 ;
    for(int i = 0 ; i < len ; i++)
    {
        if(nums[i]%divisor == 0)
        {
            sum += nums[i]/divisor ;
        }
        else sum += nums[i]/divisor + 1 ;
    }
    return sum ;
}
int Solution :: smallestDivisor(vector<int>& nums , int threshold)
{
    int left = 1 , right = *max_element(nums.begin() , nums.end()) ;
    int divisor = INT_MAX ;
    while(left < right)
    {
        int mid = left + (right - left)/2 ;
        int tempThreshold = findThreshold(nums , mid) ;
        if(tempThreshold > threshold)left = mid + 1 ;
        else 
        {
            right = mid ;
            divisor = min(mid , divisor) ;
        }
    }
    
    return divisor ;
}
