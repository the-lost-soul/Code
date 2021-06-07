class Solution {
public:
    int numTeams(vector<int>& rating) ;
};

int Solution :: numTeams(vector<int>& rating)
{
    int team = 0 ;
    int len = rating.size() ;
    for(int i = 0 ; i < len - 2 ; i++)
    {
        for(int j = i + 1 ; j < len - 1 ; j++)
        {
            for(int k = j + 1 ; k < len ; k++)
            {
                if(rating[i] > rating[j] and rating[j] > rating[k])
                    team++ ;
                else if(rating[i] < rating[j] and rating[j] < rating[k])
                    team++ ;
            }
        }
    }
    return team ;
}
