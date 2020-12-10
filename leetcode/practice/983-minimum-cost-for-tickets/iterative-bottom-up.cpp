class Solution {
public:
    
    int mincostTickets(vector<int>& days, vector<int>& costs) ;
};

int Solution :: mincostTickets(vector<int>& days , vector<int>& costs)
{
    unordered_set<int>hash(days.begin() , days.end()) ;
    vector<int>dp(days[days.size() - 1] + 1 , 0) ;
    for(int day = 1 ; day <= days[days.size() - 1] ; day++)
    {
        if(hash.find(day) == hash.end())
            dp[day] = dp[day - 1] ;
        else
        {
            int oneDayBook = costs[0] + dp[day - 1] ;
            int sevenDayBook = costs[1] + dp[max(0 , day - 7)] ;
            int thirtyDayBook = costs[2] + dp[max(0 , day - 30)] ;
            dp[day] = min(oneDayBook , min(sevenDayBook , thirtyDayBook)) ;
        }
    }
    return dp[days[days.size() - 1]] ;
}
