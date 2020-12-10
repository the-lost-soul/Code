class MyCalendar {
public :
    map<int , int>sortedInterval ;
    MyCalendar() ;
    bool book(int start , int end) ;
} ;

/*
 * Your MyCalendar object will be instantiated and called as such:
 * MyCalendar* obj = new MyCalendar();
 * bool param_1 = obj->book(start,end);
 */

MyCalendar :: MyCalendar()
{
    
}

bool MyCalendar :: book(int start , int end)
{
    bool ans = true ;
    bool insertInterval = true ;
    for(auto interval : sortedInterval)
    {
        if(start < interval.second and end > interval.first)
        {
            insertInterval = false ;
            ans = false ;
            break ;
        }
    }
    if(insertInterval)
    {
        sortedInterval[start] = end ;
    }
    return ans ;
}
