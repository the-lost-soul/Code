class Solution {
public:
    int maxScoreSightseeingPair(vector<int>& A) ;
};

int Solution :: maxScoreSightseeingPair(vector<int>& A)
{
    int n = A.size() ;
    int endGain = INT_MIN;
    int result = INT_MIN ;
     
    for(int i = n - 2 ; i >= 0 ; i--)
    {
        endGain = max(endGain , A[i + 1] - (i + 1)) ;
        result = max(result , endGain + A[i] + i) ;
    }
    
    return result ;
}
