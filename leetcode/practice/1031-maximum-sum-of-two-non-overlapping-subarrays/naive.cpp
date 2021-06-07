class Solution {
public:
    int maxSumTwoNoOverlap(vector<int>& A, int L, int M) ;
};


int Solution :: maxSumTwoNoOverlap(vector<int>& arr , int L , int M)
{
    int len = arr.size() ;
    vector<int> arrL ;
    int sum = 0 ;
    for(int i = 0 ; i < L ; i++)
    {
        sum += arr[i] ;
    }

    arrL.push_back(sum) ;

    for(int i = 1 ; i <= len - L ; i++)
    {
        sum -= arr[i - 1] ;
        sum += arr[i + L - 1] ;
        arrL.push_back(sum) ;
    }
    // printVector(arrL) ;
    vector<int> arrM ; 
    sum = 0 ;
    for(int i = 0 ; i < M ; i++)
        sum += arr[i] ;
    arrM.push_back(sum) ;

    for(int i = 1 ; i <= len - M ; i++)
    {
        sum -= arr[i - 1] ;
        sum += arr[i + M - 1] ;
        arrM.push_back(sum) ;
    }
    // printVector(arrM) ;
    int ans = INT_MIN ;
    for(int i = 0 ; i < arrL.size() ; i++)
    {
        int startL = i , endL = i + L - 1 ;
        for(int j = 0 ; j < arrM.size() ; j++)
        {
            int startM = j , endM = j + M - 1 ;
            if(startL > endM or endL < startM)
            {
                ans = max(ans , arrL[i] + arrM[j]) ;
            }
        }
    }
    return ans ;
}
