class Solution {
public:
    int busyStudent(vector<int>& startTime, vector<int>& endTime, int queryTime) ;
};

int Solution :: busyStudent(vector<int>& startTime , vector<int>& endTime , int queryTime)
{
    int len = startTime.size() , ans = 0 ;
    for(int i = 0 , j = 0 ; i < len ; i++ , j++)
    {
        if(startTime[i] <= queryTime and endTime[i] >= queryTime)
        {
            ans++ ;
        }
    }
    return ans ;
}
