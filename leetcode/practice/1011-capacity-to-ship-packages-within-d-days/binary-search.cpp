class Solution {
public:
    int shipWithinDays(vector<int>& weights, int d) ;
    int countDays(vector<int>& weights , int wt) ;
};

int Solution :: countDays(vector<int>& weights , int wt)
{
    int days = 1 , sum = 0 ;
    for(auto ele : weights)
    {
        sum += ele ;
        if(sum > wt)
        {
            sum = ele ;
            days++ ;
        }
    }
    return days ;
}
int Solution :: shipWithinDays(vector<int>& weights , int d)
{
    int len = weights.size() ;
    int right = accumulate(begin(weights) , end(weights) , 0) ;
    int left = max(right/d , *max_element(begin(weights) , end(weights))) ;
    
    while(left < right)
    {
        int mid = (left + right)/2 ;
        int days = countDays(weights , mid) ;
        if(days <= d)
        {
            right = mid ;
        }
        else left = mid + 1 ;
    }
    return left ;
}
