class Solution
{
public:
    static bool comp(vector<int>& a , vector<int>& b)
    {
        if(a[0] == b[0])
            return a[1] < b[1] ;
        return a[0] < b[0] ;
    }
    vector<vector<int>> merge(vector<vector<int>>& intervals)
    {
        sort(intervals.begin() , intervals.end() , comp) ;
        vector<vector<int>> ans ;
        for(int i = 0 ; i < intervals.size() ; i++)
        {
            if(ans.empty() || ans.back()[1] < intervals[i][0])
                ans.push_back(intervals[i]) ;
            else
               ans.back()[1] = max(ans.back()[1] , intervals[i][1]) ; 
        }
        return ans ;
    }
};
