class Solution {
public:
    int maxScoreSightseeingPair(vector<int>& A) ;
};

int Solution :: maxScoreSightseeingPair(vector<int>& A)
{
    // if(A.length == 2) return (A[0] + A[1] + 1 - 0 ) ;
    int pair = INT_MIN ;
    for(int i = 0 ; i < A.size() ; i++)
    {
        for(int j = i + 1 ; j < A.size() ; j++)
        {
            pair = max(pair , A[i] + A[j] + i - j) ;
        }
    }
    
    return pair ;
}
