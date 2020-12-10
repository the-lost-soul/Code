class Solution {
public:
    int minSetSize(vector<int>& arr) ;
};

int Solution :: minSetSize(vector<int>& arr)
{
    unordered_map<int , int>valAndFreq ;
    for(auto ele : arr)
        valAndFreq[ele]++ ;
    
    multiset<int , greater<int>>freq ;
    for(auto ele : valAndFreq)
        freq.insert(ele.second) ;
    
    int ans = 0 , runningFreq = 0 ;
    for(auto ele : freq)
    {
        ans++ ;
        runningFreq += ele ;
        if(2*runningFreq >= arr.size())break ;
    }
    return ans ;
}
