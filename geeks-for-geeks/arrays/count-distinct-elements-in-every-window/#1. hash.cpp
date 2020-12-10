/* Consider every window and get the count of distinct element
 * using hash map .
 */
void countDistinct(int arr[] , int window , int size)
{
    unordered_map<int , int>hash ;
    int count = 0 ;
    for(int i = 0 ; i < window ; i++)
    {
        if(hash[arr[i]] == 0)
            count++ ;
        hash[arr[i]]++ ;
    }
    cout << count << " " ;
    for(int i = window ; i < size ; i++)
    {
        // Delete the element's contribution which is out of 
        // bound of current window .
        hash[arr[i - window]]-- ;
        // If the element after deletion has hash value zero
        // then , this element may or may not be present in 
        // next window , hence decrease count .
        if(hash[arr[i - window]] == 0)count-- ;
        // Now consider the last element of cuurent window , if we have
        // seen this element for first time then increment  .
        if(hash[arr[i]] == 0)
            count++ ;
        hash[arr[i]]++ ;
        cout << count << " " ;
    }
}
