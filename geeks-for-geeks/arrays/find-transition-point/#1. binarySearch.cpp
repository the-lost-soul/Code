int transitionPoint(int arr[],int n)
{
    int lowerBound = 0 ;
    int upperBound = n - 1 ;
    
    while(lowerBound <= upperBound)
    {
        int mid = lowerBound + (upperBound - lowerBound)/2 ;
        
        // If mid contains 0 , update lowerBound and search in right of array .
        if(arr[mid] == 0) lowerBound = mid + 1;
        
        // If mid contains 1 , then-->
        else if(arr[mid] == 1)
        {
            // check if mid contains left-most one , if yes return that .
            if(arr[mid - 1] == 0) return mid ;
            
            // If not , then update upperBound and search in left array .
            upperBound = mid - 1;
        }
    }
    
    return -1 ;
}
