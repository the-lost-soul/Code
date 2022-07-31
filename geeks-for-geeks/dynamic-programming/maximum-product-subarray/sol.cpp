class Solution
{
public:

	long long maxProduct(vector<int> arr, int n)
    {
        long long int maxProd = arr[0] , minProd = arr[0] ;
        long long int ans = arr[0] ;
        for(int i = 1 ; i < n ; i++)
        {
            if(arr[i] < 0)
                swap(maxProd , minProd) ;
            maxProd = max((long long)arr[i] , maxProd*arr[i]) ;
            minProd = min((long long)arr[i] , minProd*arr[i]) ;
            ans = max(maxProd , ans ) ;
        }
        return ans ;
	}
};
