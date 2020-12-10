class Solution {
public:
    int findMinDifference(vector<string>& timePoints) ;
};

int Solution :: findMinDifference(vector<string>& timePoints)
{
    sort(begin(timePoints) , end(timePoints)) ;
    int ans = INT_MAX , n = timePoints.size() ;
    for(int i = 0 ; i < n ; i++)
    {
        string s1 = timePoints[i] , s2 = timePoints[(i - 1 + n)%n] ;
        int hour1 = stoi(s1.substr(0 , 2)) , min1 = stoi(s1.substr(3 , 2)) ;
        int hour2 = stoi(s2.substr(0 , 2)) , min2 = stoi(s2.substr(3 , 2)) ;
        int minDiff = abs((hour2 - hour1)*60 + (min2 - min1)) ;
        minDiff = min(minDiff , 1440 - minDiff) ;
        ans = min(ans , minDiff) ;   
    }
    return ans ;
}
