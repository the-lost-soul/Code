class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) ;
};


int Solution :: maxScore(vector<int>& cardPoints , int k)
{
    int sum = accumulate(cardPoints.begin() , cardPoints.begin() + k , 0) ;
    int ans = sum , left = cardPoints.size() - 1 , right = k - 1 ;
    for(int i = left ; i >= left - k and right >= 0 ; i-- , right--)
    {
        sum = sum + cardPoints[i] - cardPoints[right] ;
        ans = max(ans , sum) ;
    }
    return ans ;
}
