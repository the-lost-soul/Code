class Solution {
public:
    string frequencySort(string s) ;
};

bool sortByFreq(const pair<int , char>& a , const pair<int , char>& b)
{
    if(a.first > b.first)return true ;
    if(a.first < b.first)return false ;
    return a.second < b.second ;
}

string Solution :: frequencySort(string s)
{
    unordered_map<char , int>hash ;
    for(auto ch : s)
    {
       hash[ch]++ ;
    }
    vector<pair<int , char>>freq ;
    for(auto ele : hash)
    {
        freq.push_back({ele.second , ele.first}) ;
    }
    
    sort(begin(freq) , end(freq) , sortByFreq) ;
    string ans = "" ;
    for(auto ele : freq)
    {
        int count = ele.first ;
        while(count-- > 0)
        {
            ans += ele.second ;
        }
    }
    return ans ;
}
