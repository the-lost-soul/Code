class Solution {
public:
    bool checkInclusion(string s1, string s2) ;
};

bool Solution :: checkInclusion(string a , string b)
{
    if(a.size() > b.size())return false ;
    vector<int>countA(26 , 0) ;
    for(auto ch : a)countA[ch - 'a']++ ;
    vector<int>countB(26 , 0) ;
    for(int i = 0 ; i < a.size() ; i++)countB[b[i] - 'a']++ ;
    if(countA == countB)return true ;
    for(int i = a.size() ; i < b.size() ; i++)
    {
        countB[b[i - a.size()] - 'a']-- ;
        countB[b[i] - 'a']++ ;
        if(countB == countA)return true ;
    }
    return false ;
}
