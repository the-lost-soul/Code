bool findTriplets(int arr[], int size)
{ 
    sort(arr , arr + size) ;
    int left = 0 , right = size - 1 ;
    // Here ith index is fixed and we search for all other pairs .
    for(int i = 0 ; i < size - 2 ; i++)
    {
        left = i + 1 ;
        right = size - 1 ;
        while(left < right)
        {
            if(arr[i] + arr[right] + arr[left] == 0)return true ;
            if(arr[i] + arr[right] + arr[left] > 0)right-- ;
            else if(arr[i] + arr[right] + arr[left] < 0)left++ ;
            
        }
    }
    return false ;
}
