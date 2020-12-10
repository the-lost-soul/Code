class Solution {
public:
    int largestSumAfterKNegations(vector<int>& A, int K) ;
};

int Solution :: largestSumAfterKNegations(vector<int>& A, int K)
{
    // Sort the vector in increasing order
    sort(A.begin() , A.end()) ;
    
    // Calculate the initial sum .
    int sum = accumulate(A.begin() , A.end() , 0) ;
    
    // If some elements of vector are negative , then --
    while(K)
    {
        /* Negate the first element i.e the smallest element
         * or we can say that the element whose absolute value is largest .
         */
        A[0] = -A[0] ;
        
        // Sort the vector again to obtain the new sorted vector .
        sort(A.begin() , A.end()) ;
        K -- ;
    }
    
    // After k negations , again calculate the sum .
    sum = accumulate(A.begin() , A.end() , 0) ;
    
    return sum ;
    
}
