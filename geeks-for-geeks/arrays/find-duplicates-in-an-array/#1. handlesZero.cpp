/* It handles the case when array has zero as element , but it doesn't
 * handle the case when an element can be repeated more than twice .
 * eg -- 1 2 2 1 1 1
 * Output should be - 2 1 , but output comes to be 2 1 1 using below code .
 */
void printDuplicates(int arr[] , int n)
{
    bool duplicateFound = false ;
    for(int i = 0 ; i < n ; i++)
    {
        // Explicitily handle the case when array contains zero .
        if(arr[i] == INT_MIN and arr[0] < 0)
        {
            cout << "0 " ;
            duplicateFound = true ;
        }
        else if(arr[i] != INT_MIN and arr[abs(arr[i])] < 0)
        {
            cout << abs(arr[i]) << " " ;
            duplicateFound = true ;
        }
        else if(arr[i] != INT_MIN)
        {
            if(arr[abs(arr[i])] == 0)arr[abs(arr[i])] = INT_MIN ;
            else arr[abs(arr[i])] = -arr[abs(arr[i])] ;
        }
        else
        {
            arr[0] = -arr[0] ;
        }
    }
    
    if(duplicateFound == false)cout << "-1" ;

}
