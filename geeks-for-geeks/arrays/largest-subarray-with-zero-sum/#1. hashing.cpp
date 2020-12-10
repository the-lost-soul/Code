int maxLen(int arr[] , int n)
{
    unordered_map<int , int>hash ;
    int sum = 0 ;
    int maxLen = 0 ;
    for(int i = 0 ; i < n ; i++)
    {
        sum += arr[i] ;
        // If sum till current sub-array starting from index is 0 , 
        // then length is i + 1 .
        if(sum == 0)maxLen = i + 1 ;
        // If we get a sum which we have seen earlier , then
        // this means that their is a sub-array b/w them , such
        // that their sum is zero .
        if(hash.find(sum) != hash.end())
        {
            maxLen = max(maxLen , i - hash[sum]) ;
        }
        else hash[sum] = i ;
    }
    return maxLen ;
}
