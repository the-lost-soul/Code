class Solution {
public:
    int maxWidthRamp(vector<int>& arr) ;
};

int Solution :: maxWidthRamp(vector<int>& arr)
{
    int len = size(arr) ;
    int right[len] ;
    right[0] = arr[0] ;
    for(int i = 1 ; i < len ; i++)
    {
        right[i] = min(arr[i] , right[i - 1]) ;
    }
    
    int left[len] ;
    left[len - 1] = arr[len - 1] ;
    for(int i = len - 2 ; i >= 0 ; i--)
    {
        left[i] = max(arr[i] , left[i + 1]) ;
    }
    int i = 0 , j = 0 , ans = 0 ;
    while(i < len and j < len)
    {
        if(right[i] <= left[j])
        {
            ans = max(ans , j - i) ;
            j++ ;
        }
        else i++ ;
    }
    return ans ;
}
