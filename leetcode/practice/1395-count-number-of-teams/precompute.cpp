class Solution {
public:
    int numTeams(vector<int>& rating) ;
};

int Solution :: numTeams(vector<int>& rating)
{
    int len = rating.size() ;
    vector<int>greater(len , 0) , less(len , 0) ;
    for(int i = 0 ; i < len - 1 ; i++)
    {
        for(int j = i + 1 ; j < len ; j++)
        {
            if(rating[i] < rating[j])
                greater[i]++ ;
            else
                less[i]++ ;
        }
    }
    
    int res = 0 ;
    for(int i = 0 ; i < len - 1 ; i++)
    {
        for(int j = i + 1 ; j < len ; j++)
        {
            if(rating[i] < rating[j])
            {
                res += greater[j] ;
            }
            else res += less[j] ;
        }
    }
    return res ;
}
