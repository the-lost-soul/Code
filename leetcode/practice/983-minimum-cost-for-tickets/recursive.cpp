class Solution {
public:
    unordered_set<int>hash ;
    int mincostTickets(vector<int>& days, vector<int>& costs) ;
    int helper(vector<int>& days , vector<int>& costs , int currentDay) ;
};

int Solution :: helper(vector<int>& days , vector<int>& costs , int currentDay)
{
    if(currentDay > days[days.size() - 1])return 0 ;
    if(hash.find(currentDay) == hash.end())
        return helper(days , costs , currentDay + 1) ;
    int oneDayBook = costs[0] + helper(days , costs , currentDay + 1) ;
    int sevenDayBook = costs[1] + helper(days , costs , currentDay + 7) ;
    int thirtyDayBook = costs[2] + helper(days , costs , currentDay + 30) ;
    return min(oneDayBook , min(sevenDayBook , thirtyDayBook)) ;
}
int Solution :: mincostTickets(vector<int>& days , vector<int>& costs)
{
    for(int i = 0 ; i < days.size() ; i++)
    {
        hash.insert(days[i]) ;
    }
    return helper(days , costs , 1) ;
}
