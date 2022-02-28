class Solution 
{
public:
    vector<int> getStrongest(vector<int>& arr, int k) ;
};
int median ;

bool comp(const int ele1 , const int ele2)
{
    if(abs(ele1 - median) == abs(ele2 - median))return ele1 > ele2 ;
    return abs(ele1 - median) > abs(ele2 - median) ;
}
vector<int> Solution :: getStrongest(vector<int>& arr, int k)
{
    int n = arr.size() ;
    vector<int> temp = arr ;
    sort(begin(temp) , end(temp)) ;
    median = temp[(n - 1)/2] ;
        
    sort(begin(temp) , end(temp) , comp) ;
    temp.resize(k) ;
    return temp ;
    
}
