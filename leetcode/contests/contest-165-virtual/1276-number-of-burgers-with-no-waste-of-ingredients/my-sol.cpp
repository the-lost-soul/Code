class Solution {
public:
    vector<int> numOfBurgers(int tomatoSlices, int cheeseSlices) ;
};


vector<int> Solution :: numOfBurgers(int tomato , int cheese)
{
    if(tomato%2 != 0 or (cheese >= tomato and cheese != 0))return {} ;
    int jumbo = 0 , small = 0 ;
    if(tomato%4 == 0)
    {
        if(cheese == tomato/4)
        {
            jumbo = cheese ;
            small = 0 ;
        }
        else if(cheese > tomato/4)
        {
            small = 2*(cheese - tomato/4) ;
            jumbo = cheese - small ;
        }
        else
        {
            return {} ;
        }
    }
    else
    {
        if(cheese == tomato/2)
        {
            jumbo = 0 ;
            small = cheese ;
        }
        else if(cheese < tomato/2)
        {
            jumbo = tomato/2 - cheese ;
            small = cheese - jumbo ;
        }
        else
        {
            return {} ;
        }
    }
    if(jumbo >= 0 and small >= 0)return {jumbo , small} ;
    return {} ;
}
