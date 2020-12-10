class Solution {
public:
    int maxSatisfied(vector<int>& customers, vector<int>& grumpy, int X) ;
};

int Solution :: maxSatisfied(vector<int>& customers, vector<int>& grumpy, int X)
{
    int powSatisfied = 0 ;
    // Get the number of customers who feel satisfied using power 
    // when owner is grumpy
    for(int i = 0 ; i < X ; i++)
    {
        if(grumpy[i] == 1)powSatisfied += customers[i] ;
    }
    
    int maxPowSatisfied = powSatisfied , winStart = 0 , winEnd = X ;
    for(int i = 1 ; i <= customers.size() - X ; i++)
    {
        if(grumpy[i - 1] == 1)
        {
            powSatisfied -= customers[i - 1] ;
        }

        if(grumpy[i + X - 1] == 1)
        {
            powSatisfied += customers[i + X - 1] ;
        }
        // If in current window(i.e X minutes) , there are more number of
        // customers who are satisfied , then update .
        if(powSatisfied > maxPowSatisfied)
        {
            maxPowSatisfied = powSatisfied ;
            winStart = i ;
            winEnd = i + X ;
        }
        
    }
    int ans = 0 ;
    for(int i = 0 ; i < grumpy.size() ; i++)
    {
        if(grumpy[i] == 0)ans += customers[i] ;
        else if(i >= winStart and i < winEnd)ans += customers[i] ;
    }
    return ans ;
}
