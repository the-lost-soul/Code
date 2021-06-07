class Solution {
public:
    int removeCoveredIntervals(vector<vector<int>>& intervals) ;
};

int Solution :: removeCoveredIntervals(vector<vector<int>>& intervals)
{
    sort(intervals.begin() , intervals.end()) ;
    int prev = 0 ;
    for(int i = 1 ; i < intervals.size() ; i++)
    {
        if(intervals[prev][0] <= intervals[i][0] and intervals[prev][1] >= intervals[i][1])
        {
            intervals[i][0] = -1 ;
            intervals[i][1] = -1 ;
        }
        else prev = i ;
    }
    int ans = 0 ;
    for(int i = 0 ; i < intervals.size() ; i++)
    {
        if(intervals[i][0] != -1 and intervals[i][1] != -1)
            ans++ ;
    }
    
    return ans ;
}
