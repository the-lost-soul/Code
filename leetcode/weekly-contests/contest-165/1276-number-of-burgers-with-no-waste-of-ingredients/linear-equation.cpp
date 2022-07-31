class Solution {
public:
    vector<int> numOfBurgers(int tomatoSlices, int cheeseSlices) ;
};

/* Form linear equation -- 
 * 1 -- We know , number of cheese slices is equal to total burgers i.e
 *       -- cheeseSlices = jumbo + small .
 * 2 -- Also , number of tomato slices is equal to 4*(total jumbo burgers)
 *       plus 2*(total small burgers) i.e -- tomatoSlices = 4*jumbo + 2*small
 */
vector<int> Solution :: numOfBurgers(int tomato , int cheese)
{
    if(tomato%2 != 0)return {} ;
    int jumbo = tomato/2 - cheese ;
    int small = 2*cheese - tomato/2 ;
    if(jumbo >= 0 and small >= 0) return {jumbo , small} ;
    return {} ;
}
