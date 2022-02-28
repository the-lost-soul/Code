class Solution {
public:
    int minDays(vector<int>& bloomDay, int m, int k) ;
};

int Solution :: minDays(vector<int>& bloomDay , int m , int k)
{
    if(m*k > bloomDay.size())return -1 ;
    
    int minDay = *min_element(bloomDay.begin() , bloomDay.end()) ;
    int maxDay = *max_element(bloomDay.begin() , bloomDay.end()) ;
    
    while(minDay <= maxDay)
    {
        int mid = minDay + (maxDay - minDay)/2 ;
        int j = 0 , bouqets = 0 ;
        while(j <= bloomDay.size() - k)
        {
            bool notBloomed = false ;
            for(int i = j ; i < j + k ; i++)
            {
                if(bloomDay[i] > mid)
                {
                    notBloomed = true ;
                    j = i + 1 ;
                    break ;
                }
            }
            if(notBloomed == false)
            {
                bouqets++ ;
                j += k ;
            }
        }
        if(m <= bouqets) maxDay = mid - 1 ;
        else minDay = mid + 1 ; 
    }
    return minDay ;
}
