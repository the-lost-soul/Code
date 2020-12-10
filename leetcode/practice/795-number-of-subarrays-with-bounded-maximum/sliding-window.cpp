class Solution {
public:
    int numSubarrayBoundedMax(vector<int>& arr , int lowerLim , int upperLim) ;
};

int Solution :: numSubarrayBoundedMax(vector<int>& arr , int lower , int upper)
{
    int i = 0 , j = 0 , ans = 0 , subarr = 0 ;
    while(j < arr.size())
    {
        if(arr[j] >= lower and arr[j] <= upper)
        {
            subarr = j - i + 1 ;
        }
        else if(arr[j] > upper)
        {
            subarr = 0 ;
            i = j + 1 ;
            
        }
        ans += subarr ;
        j++ ;
    }
    return ans ;
}
