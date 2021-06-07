class Solution {
public:
    int maxSumTwoNoOverlap(vector<int>& A, int L, int M) ;
};

int Solution :: maxSumTwoNoOverlap(vector<int>& arr , int L , int M)
{
    int len = arr.size() ;
    vector<int> prefixSum(len , 0);
    prefixSum[0] = arr[0] ;
    for(int i = 1 ; i < len ; i++)
        prefixSum[i] = prefixSum[i - 1] + arr[i] ;

    int maxL = prefixSum[L - 1] , maxM = prefixSum[M - 1] , res = prefixSum[L + M - 1] ;
    for(int i = L + M ; i < prefixSum.size() ; i++)
    {
        maxL = max(maxL , prefixSum[i - M] - prefixSum[i - L - M ]) ;
        res = max(res , maxL + prefixSum[i] - prefixSum[i - M]) ;
    }
    
    for(int i = L + M ; i < prefixSum.size() ; i++)
    {
        maxM = max(maxM , prefixSum[i - L] - prefixSum[i - L - M]) ;
        res = max(res , maxM + prefixSum[i] - prefixSum[i - L]) ;
    }
    return res ;
}
