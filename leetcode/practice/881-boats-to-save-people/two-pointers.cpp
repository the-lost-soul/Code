class Solution
{
public:
    int numRescueBoats(vector<int>& people, int limit)
    {
        sort(begin(people) , end(people)) ;

        int left = 0 , right = people.size() - 1 ;
        int ans = 0 ;
        while(left <= right)
        {
            // when there's only one person left .
            if(left == right)
            {
                ans++ ;
                left++ ;
                right-- ;
            }
            else if(people[left] + people[right] <= limit)
            {
                ans++ ;
                left++ ;
                right-- ;
            }
            else
            {
                ans++ ;
                right-- ;
            }
        }
        return ans ;
    }
};
