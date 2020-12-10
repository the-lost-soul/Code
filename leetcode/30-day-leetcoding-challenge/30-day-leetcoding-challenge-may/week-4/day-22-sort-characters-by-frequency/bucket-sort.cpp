class Solution {
public:
    string frequencySort(string s) ;
};

string Solution :: frequencySort(string s)
{
    unordered_map<char , int>hash ;
    for(auto ch : s)
    {
       hash[ch]++ ;
    }
    vector<string>bucket(s.size() + 1 , "") ;
    for(auto ele : hash)
    {
        bucket[ele.second].append(ele.second , ele.first) ;
    }
    
    string ans = "" ;
    for(int i = s.size() ; i > 0 ; i--)
    {
        if(!bucket[i].empty())
        {
            ans.append(bucket[i]) ;
        }
    }
    return ans ;
}
