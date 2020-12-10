class Solution {
public:
    int numWaterBottles(int numBottles, int numExchange) ;
};

int Solution :: numWaterBottles(int numBottles , int numExchange)
{
    int stock = 0 ;
    int drink = 0 ;
    while(numBottles != 0)
    {
        drink += numBottles ;
        
        // Exchange these bottles with filled bottles
        if((numBottles + stock)%numExchange == 0)
        {
            numBottles = (numBottles + stock)/numExchange ;
            stock = 0 ;
        }
        else
        {
            int temp = (numBottles + stock)/numExchange ;
            stock = (numBottles + stock)%numExchange ;
            numBottles = temp ;
        }        
    }
    return drink ;
}
