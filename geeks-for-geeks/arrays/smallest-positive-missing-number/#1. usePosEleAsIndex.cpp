int missingNumber(int arr[], int n) 
{
    /* We are using another vector to store the positive numbers 
     * because we do not want to de-structure the original array .
     * First get all the positive numbers in vector .
     */
    vector<int>vec ;
    for(int i = 0 ; i < n ; i++)
    {
        if(arr[i] > 0)vec.push_back(arr[i]) ;
    }
    
    int len = vec.size() ;
    for(int i = 0 ; i < len ; i++)
    {
        /* Use current element as the index and check if it is within
         * range [1 , len] . If yes, then using it as index , mark 
         * the element at that position as neagative .
         */
        if(abs(vec[i]) >= 1 and abs(vec[i]) <= len)
        {
            if(vec[abs(vec[i]) - 1] > 0)
            {
                vec[abs(vec[i]) - 1] = -vec[abs(vec[i]) - 1] ;
            }
        }
    }
    
    /* Get the first positive elment as that element is not present
     * in the vector because if it would have been present , then
     * that position should have been marked negative .
     */
    for(int i = 0 ; i < len ; i++)
    {
        if(vec[i] > 0)
        {
            return i + 1 ;
        }
    }
    
    return len ;
} 
