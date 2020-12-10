/* It doesn't preserve the order of repeated element .
 * So , the answer which we will get will be correct but
 * it's order won't be preserved .
 */
void printDuplicates(int arr[] , int n)
{
    
    for(int i = 0 ; i < n ; i++)
    {
        arr[arr[i]%n] += n ;
    }
    bool duplicateFound = false ;
    for(int i = 0 ; i < n ; i++)
    {
        /* The division of current element with n will produce a result
         * greater than 1 only when it is repeated more than twice .
         */
        if(arr[i]/n > 1)
        {
            /* Print the current element . The current index will be desired
             * answer because array contains element in range [0 , n-1]
             */
            cout << i << " " ;
            duplicateFound = true ;
        }
    }
    
    if(duplicateFound == false)cout << "-1" ;

}
