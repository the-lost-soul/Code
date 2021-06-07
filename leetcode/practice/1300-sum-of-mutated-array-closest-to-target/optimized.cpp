class Solution {
public:
    int findBestValue(vector<int>& arr, int target) ;
};

int Solution :: findBestValue(vector<int>& arr , int target)
{
    sort(begin(arr) , end(arr)) ;
    long value = INT_MAX ;
    int ind = 0 , len = arr.size() ;
    while(ind < len and target > arr[ind]*(len - ind))
    {
        target -= arr[ind++] ;
    }
    
    if(ind == len)
        return arr[ind - 1] ;
    int val = round((target - 0.0001)/(len - ind)) ;
    return val ;
}
