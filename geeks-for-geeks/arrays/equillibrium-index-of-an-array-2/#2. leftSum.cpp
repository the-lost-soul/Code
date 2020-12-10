int findEquilibrium(int arr[], int n)
{
    int prefixSum  = 0 ;
    for(int i = 0 ; i < n ; i++)prefixSum += arr[i] ;
    
    int leftSum = 0 ;
    for(int i = 0 ; i < n ; i++)
    {
        prefixSum -= arr[i] ;
        if(prefixSum == leftSum)return i ;
        leftSum += arr[i] ;
    }
    return -1 ;
}
