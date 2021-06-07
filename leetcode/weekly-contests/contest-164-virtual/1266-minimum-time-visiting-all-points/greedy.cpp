class Solution {
public:
    int minTimeToVisitAllPoints(vector<vector<int>>& points) ;
};

int Solution :: minTimeToVisitAllPoints(vector<vector<int>>& points)
{
    int timeTaken = 0 ;
    for(int i = 0 ; i < points.size() - 1 ; i++)
    {
        timeTaken += max(abs(points[i][0] - points[i + 1][0]) , abs(points[i][1] - points[i + 1][1])) ;
    }
    return timeTaken ;
}
