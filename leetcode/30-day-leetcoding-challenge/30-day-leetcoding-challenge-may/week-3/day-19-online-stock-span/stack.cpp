class StockSpanner {
    vector<pair<int , int>>span ;
public:
    StockSpanner() 
    {
    }
    
    int next(int price) 
    {
        int days = 1 ;
        while(!span.empty() and span.back().first <= price)
        {
            days += span.back().second ;
            span.pop_back() ;
        }
        span.push_back({price , days}) ;
        return days ;
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */
