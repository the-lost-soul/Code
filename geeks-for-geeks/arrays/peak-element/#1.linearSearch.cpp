int peakElement(int arr[], int n)
{
    if(n == 1)return n-1 ;
    for(int i = 0 ; i < n ; i++)
    {
        
        if(i == 0 and arr[i] >= arr[i+1])return i ;
        if(i == n - 1 and arr[i] >= arr[i-1])return i ;
        if(arr[i] >= arr[i+1] and arr[i] >= arr[i-1])return i ;
    }
}
