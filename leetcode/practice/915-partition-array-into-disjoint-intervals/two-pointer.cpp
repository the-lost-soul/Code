class Solution {
public:
    int partitionDisjoint(vector<int>& arr) ;
};

int Solution :: partitionDisjoint(vector<int>& arr)
{
    
    int left = 0 , right = 1 , maxEle1 = arr[0] , maxEle2 = INT_MIN ;
    int ans = 1 ;
    while(right < size(arr))
    {
        while(right < size(arr) and maxEle1 <= arr[right])
        {
            maxEle2 = max(maxEle2 , arr[right]) ;
            right++ ;
        }
        if(right < size(arr))
        {
            maxEle1 = max(maxEle1 , maxEle2) ;
            ans = right + 1 ;
        }
        right++ ;
    }
    return ans ;
}
