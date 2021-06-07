class Solution {
public:
    vector<int> countBits(int num) ;
};

vector<int> Solution :: countBits(int num)
{
    if(num == 0)return {0} ;
    if(num == 1)return {0 , 1} ;
    vector<int>count(num + 1 , 0) ;
    count[0] = 0 ;
    count[1] = 1 ;
    for(int i = 2 ; i <= num ; i++)
    {
        if(i%2 == 0)
        {
            count[i] = count[i/2] ;
        }
        else count[i] = count[i - 1] + 1 ;
    }
    return count ;
}
