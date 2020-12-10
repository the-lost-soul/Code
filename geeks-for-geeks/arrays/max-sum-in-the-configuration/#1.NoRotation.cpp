
/* The naive approach is to get all rottions and find the max sum
 * but on observation we can see how the elements are changing their
 * priority on each ith rotation and how overall sum is getting changed .
 * Observe that for (i+1)th(indexing 0 , so i+1) rotation ith element
 * will contribute to (size - 1)*arr[i] and contribution of all other
 * array elements will decrease by a factor of 1 except that of ith element
 * as it's contribution is increasing from 0 to (size - 1) .
 */
int max_sum(int arr[] , int size)
{
    int currSum = 0 ;
    int eleWiseSum = 0 ;
    for(int i = 0 ; i < size ; i++)
    {
        currSum += i*arr[i] ;
        eleWiseSum += arr[i] ;
    }
    int maxSum = currSum ;
    for(int i = 0 ; i < size ; i++)
    {
        
        currSum = currSum - eleWiseSum + arr[i] + arr[i]*(size - 1) ;
        if(currSum > maxSum)maxSum = currSum ;
    }
    return maxSum ;
    
}
