class Solution {
public:
    int minNumberOfFrogs(string croakOfFrogs) ;
};

int Solution :: minNumberOfFrogs(string croakOfFrogs)
{
    int croak[5] ;
    memset(croak , 0 , sizeof(croak)) ;
    for(auto ch : croakOfFrogs)
    {
        if(ch == 'c')
        {
            croak[0]++ ;
            if(croak[4] != 0)croak[4]-- ;         
        }
        else if(ch == 'r')
        {
            if(croak[0] <= 0)return -1 ;
            croak[1]++ ;
            croak[0]-- ;
        }
        else if(ch == 'o')
        {
            if(croak[1] <= 0)return -1 ;
            croak[2]++ ;
            croak[1]-- ;
        }
        else if(ch == 'a')
        {
            if(croak[2] <= 0)return -1 ;
            croak[3]++ ;
            croak[2]-- ;
        }
        else if(ch == 'k')
        {
            if(croak[3] <= 0)return -1 ;
            croak[4]++ ;
            croak[3]-- ;
        }
    }
    if(croak[0] != 0 || croak[1] != 0 || croak[2] != 0 || croak[3] != 0) return -1 ;
    return croak[4] ;
}    
