class Solution
{
public:
    int maxProfit(vector<int>& prices)
    {
        if(prices.size() == 0 || prices.size() == 1)
            return 0 ;

        vector<int>buy(prices.size() + 1 , 0) ;
        vector<int>sell(prices.size() + 1 , 0) ;
        buy[1] = -prices[0] ;

        for(int i = 2 ; i <= prices.size() ; i++)
        {
            int price = prices[i - 1] ;
            buy[i] = max(buy[i - 1] , sell[i - 2] - price) ;
            sell[i] = max(sell[i - 1] , buy[i - 1] + price) ;
        }
        return sell[prices.size()] ;
    }
};
