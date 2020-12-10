/* Every time we are doing mod with n so as to get index
 * range b/w [0 , n-1] .
 */
void printDuplicates(int arr[] , int n)
{
    bool duplicateFound = false ;
    for(int i = 0 ; i < n ; i++)
    {
        /* The range i.e greater than n and less than
         * 2*n is used here for the purpose to check whether
         * it is first repetition of current element or not .
         * If so , print it and else do nothig .
         */
        if(arr[arr[i]%n] < 2*n and arr[arr[i]%n] >= n)
        {
            cout << arr[i]%n << " " ;
            duplicateFound = true ;
        }
        arr[arr[i]%n] += n ;
    }
    
    
    
    if(duplicateFound == false)cout << "-1" ;

}
