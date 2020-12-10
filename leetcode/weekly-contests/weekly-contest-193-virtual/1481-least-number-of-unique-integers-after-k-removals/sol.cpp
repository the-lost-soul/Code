class Solution {
public:
    int findLeastNumOfUniqueInts(vector<int>& arr, int k) ;
};

int Solution :: findLeastNumOfUniqueInts(vector<int>& arr , int k)
{
    unordered_map<int , int>count ;
    for(auto num : arr)
    {
        count[num]++ ;
    }
    vector<pair<int , int>>sortMap ;
    for(auto itr : count)
    {
        sortMap.push_back({itr.second , itr.first}) ;
    }
    sort(sortMap.begin() , sortMap.end()) ;
    int i = 0 ;
    while(k > 0 and i < sortMap.size())
    {
        auto itr = sortMap[i] ;
        if(k >= itr.first)
        {
            k -= itr.first ;
            sortMap[i].first = 0 ;
            if(k > 0)i++ ;
        }
        else
        {
            sortMap[i].first = itr.first - k ;
            k = 0 ;
        }
    }
    int ans = 0 ;
    for(auto itr : sortMap)
    {
        if(itr.first > 0)ans++ ;
    }
    return ans ;
}
