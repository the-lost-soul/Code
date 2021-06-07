class Solution {
public:
    int maxSatisfied(vector<int>& customers, vector<int>& grumpy, int X) ;
};

int Solution :: maxSatisfied(vector<int>& customers, vector<int>& grumpy, int X)
{
    int directlySatisfied = 0 , powSatisfied = 0 , maxSatisfied = 0 ;
    for(int i = 0 ; i < grumpy.size() ; i++)
    {
        // Customers who are satisfied without powers .
        directlySatisfied += grumpy[i] == 1 ? 0 : customers[i] ;
        // Customers who are satisfied using powers .
        powSatisfied += grumpy[i] == 1 ? customers[i] : 0 ;
        // If the current minute is greater than the value for which
        // owner can control his grumpiness , then -- 
        if(i >= X)
        {
            // Decrease the number of customer at (i - X)th minute , if 
            // owner is grumpy at that minute .
            powSatisfied -= grumpy[i - X] == 1 ? customers[i - X] : 0 ;
        }
        // Till now , the max number of customers which can be satisfied
        // using power .
        maxSatisfied = max(maxSatisfied , powSatisfied) ;
    }
    
    return directlySatisfied + maxSatisfied ;
}
