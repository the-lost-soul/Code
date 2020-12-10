class Solution {
public:
    int days[12] = {31 , 28 , 31 , 30 , 31 , 30 , 31 , 31 , 30 , 31 , 30 , 31} ;
    int dayOfYear(string date) ;
};

int Solution :: dayOfYear(string date)
{
    int year = stoi(date.substr(0 , 4)) ;
    int month = stoi(date.substr(5 , 2)) ;
    int day = stoi(date.substr(8 , 2)) ;
    
    bool leap = year%400 == 0 or(year%4 == 0 and year%100 != 0) ;
    int ans = 0 ;
    for(int m = 0 ; m < month - 1 ; m++)
    {
        // Month is february and year is leap
        if(m== 1 and leap)
        {
            ans += days[m] + 1 ;
        }
        else
        {
            ans += days[m] ;
        }
    }
    ans += day ;
    return ans ;
}
