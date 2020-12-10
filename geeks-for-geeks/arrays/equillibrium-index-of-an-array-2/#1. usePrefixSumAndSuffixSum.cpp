int findEquilibrium(int arr[], int n)
{
    /* The index where prefixSum and suffixSum will be equal is the
     * desired equillibrium index .
     */
    int prefixSum[n] = {0} ;
    prefixSum[0] = arr[0] ;
    for(int i = 1 ; i < n ; i++)prefixSum[i] += prefixSum[i - 1] + arr[i] ;
    
    int suffixSum[n] = {0} ;
    suffixSum[n - 1] = arr[n - 1] ;
    for(int i = n - 2 ; i >= 0 ; i--)suffixSum[i] += suffixSum[i + 1] + arr[i] ;
    
    for(int i = 0 ; i < n ; i++)
        if(prefixSum[i] == suffixSum[i])return i ;
    
    return -1 ;
}
