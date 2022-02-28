class Solution {
public:
    vector<int> sortByBits(vector<int>& arr) ;
};

bool comp(int first , int second)
{
    int countA = 0 , countB = 0 ;
    int a = first , b = second ;
    while(a != 0)
    {
        countA += a&1 ;
        a = a>>1 ;
    }
    
    while(b != 0)
    {
        countB += b&1 ;
        b = b>>1 ;
    }
    
   if(countA == countB)
       return first <= second ;
    
    return countA < countB ;
}
vector<int> Solution :: sortByBits(vector<int>& arr)
{
    sort(arr.begin() , arr.end() , comp) ;
    return arr ;
}
