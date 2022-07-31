class Solution
{
    public:
    int maxSumPairWithDifferenceLessThanK(int arr[] , int n , int k)
    {
        sort(arr , arr + n) ;
        int i = n - 1 , max_sum = 0 ;
        while(i > 0)
        {
            if(arr[i] - arr[i - 1] < k)
            {
                max_sum += arr[i] ;
                max_sum += arr[i - 1] ;
                i -= 2 ;
            }
            else
                i -= 1 ;
        }
        return max_sum ;
    }
};
