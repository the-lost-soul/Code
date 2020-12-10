int missingNumber(int arr[], int n) 
{
    // Segregate positive and negative numbers .
    int low = 0 , high = n - 1 ;
    while(low <= high)
    {
        if(arr[low] > 0)low++ ;
        else
        {
            swap(arr[low] , arr[high]) ;
            high-- ;
        }
    }
    
    for(int i = 0 ; i < low ; i++)
    {
        int val = abs(arr[i]) ;
        // If element is in range .
        if(val >= 1 and val <= low)
        {
            // If we have seen it first time .
            if(arr[val - 1] > 0)
            {
                // Taking current element as index , mark thr
                // value at that index as negative .
                arr[val - 1] = -arr[val - 1] ;
            }
        }
    }
    
    for(int i = 0 ; i < low ; i++)
    {
        if(arr[i] > 0)return i+1 ;
    }
    return low ;
} 
