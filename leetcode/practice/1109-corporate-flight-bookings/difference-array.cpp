class Solution {
public:
    vector<int> corpFlightBookings(vector<vector<int>>& bookings, int n) ;
};

vector<int> Solution :: corpFlightBookings(vector<vector<int>>& bookings , int n)
{
    vector<int>ans(n , 0) ;
    for(int i = 0 ; i < bookings.size() ; i++)
    {
        int ithFlight = bookings[i][0] , jthFlight = bookings[i][1] ;
        int seats = bookings[i][2] ;
        
        ans[ithFlight - 1] += seats ;
        if(jthFlight != n)
        {
            ans[jthFlight] -= seats ;
        }
    }
    
    for(int i = 1 ; i < n ; i++)
    {
        ans[i] += ans[i - 1] ;
    }
    return ans ;
}
