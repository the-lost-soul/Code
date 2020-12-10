class Solution {
public :
    int numTimesAllBlue(vector<int>& light) ;
} ;

int Solution :: numTimesAllBlue(vector<int>& lights)
{
    vector<int>states(lights.size() + 1 , 0) ;
    bool noBlue = false ;
    int moments = 0 , maxBlue = 0 ;
    for(int m = 0 ; m < lights.size() ; m++)
    {
        states[lights[m] - 1] = 1 ;
        while(maxBlue < lights.size() and states[maxBlue])
            maxBlue++ ;
        moments += maxBlue == m + 1 ;
    }
    return moments ;
}
