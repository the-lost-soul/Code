class Solution {
public:
    int findBestValue(vector<int>& arr, int target) ;
};

int Solution :: findBestValue(vector<int>& arr , int target)
{
    sort(begin(arr) , end(arr)) ;
    long value = INT_MAX ;
    int ind = 0 , prefixSum = 0 ;
    int initialTarget = abs(accumulate(begin(arr) , end(arr) , 0) - target) ;
    for(int v = 0 ; v <= target ; v++)
    {
        while(ind < arr.size() and v > arr[ind])
        {
            prefixSum += arr[ind] ;
            ind++ ;
        }
        long sum = prefixSum + v*(arr.size() - ind) ;
        if(abs(sum - target) <= initialTarget)
        {
            if(abs(sum - target) == initialTarget)
            {
                value = value > v ? v : value ;
            }
            else value = v ;
            initialTarget = abs(sum - target) ;
            
        }
    }
    return value ;
}
