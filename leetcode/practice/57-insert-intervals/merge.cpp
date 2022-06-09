class Solution
{
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval)
    {
        vector<vector<int>>ans ;
        int ind = 0 ;
        while(ind < intervals.size() and intervals[ind][1] < newInterval[0])
            ans.push_back(intervals[ind++]) ;

        while(ind < intervals.size() and intervals[ind][0] <= newInterval[1])
        {
            newInterval[0] = min(newInterval[0] , intervals[ind][0]) ;
            newInterval[1] = max(newInterval[1] , intervals[ind][1]) ;
            ind++ ;
        }

        ans.push_back(newInterval) ;
        while(ind < intervals.size())
            ans.push_back(intervals[ind++]) ;
        return ans ;
    }
};
