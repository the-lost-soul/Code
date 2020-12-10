class Solution {
public:
    int days[12] = {31 , 28 , 31 , 30 , 31 , 30 , 31 , 31 , 30 , 31 , 30 , 31} ;
    int daysBetweenDates(string date1, string date2) ;
    int dayFrom1971(string date) ;
    bool isLeap(int year) ;
};

bool Solution :: isLeap(int year)
{
    return (year%4 == 0 and (year%100 != 0 || year%400 == 0)) ;
}
int Solution :: dayFrom1971(string date)
{
    int year = stoi(date.substr(0 , 4)) ;
    int month = stoi(date.substr(5 , 2)) ;
    int day = stoi(date.substr(8)) ;
    
    for(int y = 1971 ; y < year ; y++)
    {
        day += (isLeap(y) ? 366 : 365 );
    }
    
    if(isLeap(year) and month > 2)
    {
        day ++ ;
    }
    day += accumulate(begin(days) , begin(days) + month - 1 , 0) ;
    return day ;
}

int Solution :: daysBetweenDates(string date1 , string date2)
{
    return abs(dayFrom1971(date1) - dayFrom1971(date2)) ;
}
