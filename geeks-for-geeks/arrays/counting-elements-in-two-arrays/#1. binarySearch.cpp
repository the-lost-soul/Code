int binarySearch(int arr[] , int size , int ele)
{
    int left = 0 , right = size - 1 , count = 0 ;
    while(left <= right)
    {
        int mid  = (left + right)/2 ;
        if(ele < arr[mid])right = mid - 1 ;
        else
        {
            count += (mid - left + 1) ;
            left = mid + 1 ;
        }
    }
    return count ;
}
void countEleLessThanOrEqual(int arr1[] , int arr2[] , int size1 , int size2)
{
    sort(arr2 , arr2 + size2) ;
    for(int i = 0 ; i < size1 ; i++)
    {
        cout << binarySearch(arr2 , size2 , arr1[i]) << " " ;
    }
}
