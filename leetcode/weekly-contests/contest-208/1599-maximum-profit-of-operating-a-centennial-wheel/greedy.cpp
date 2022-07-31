class Solution {
public:
    int minOperationsMaxProfit(vector<int>& customers, int boardingCost, int runningCost) ;
};

int Solution :: minOperationsMaxProfit(vector<int>& customers, int boardingCost, int runningCost)
{
    int waiting = 0 ;
    int total = 0 ;
    int round = 0 , curr_round = 0 ;
    int old_cost = INT_MIN ;
    for(int i = 0 ; i < customers.size() ; i++)
    {
        waiting += customers[i] ;
        total += min(4 , waiting) ;
        waiting = max(0 , waiting  - 4) ;
        curr_round++ ;
        int curr_cost = total*boardingCost - curr_round*runningCost ;
        if(old_cost < curr_cost)
        {
            round = curr_round ;
            old_cost = curr_cost ;
        }
    }
    
    while(waiting > 0)
    {
        total += min(4 , waiting) ;
        waiting = max(0 , waiting - 4) ;
        curr_round++ ;
        int curr_cost = total*boardingCost - curr_round*runningCost ;
        if(old_cost < curr_cost)
        {
            round = curr_round ;
            old_cost = curr_cost ;
        }
    }
    return old_cost >= 0 ? round : -1 ;
}

