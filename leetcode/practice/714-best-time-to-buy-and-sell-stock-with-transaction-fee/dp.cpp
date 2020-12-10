class Solution {
public:
    int maxProfit(vector<int>& prices, int fee) ;
};

int Solution :: maxProfit(vector<int>& prices , int fee)
{
    int length = prices.size() ;
    vector<int>buy(length , 0) , sell(length , 0) ;
    buy[0] -= prices[0] ;
    for(int i = 1 ; i < length ; i++)
    {
        buy[i] = max(buy[i - 1] , sell[i - 1] - prices[i]) ;
        sell[i] = max(sell[i - 1] , buy[i - 1] + prices[i] - fee) ;
    }
    return sell[length - 1] ;
}
