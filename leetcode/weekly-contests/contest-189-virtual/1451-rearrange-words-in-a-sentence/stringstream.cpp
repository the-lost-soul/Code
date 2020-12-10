class Solution {
public:
    string arrangeWords(string text) ;
};

string Solution :: arrangeWords(string text)
{
    text[0] = tolower(text[0]) ;
    stringstream str(text) ;
    map<int , vector<string>>hash ;
    string word ;
    while(str >> word)
    {
        hash[word.size()].push_back(word) ;
    }
    string ans = "" ;
    for(auto details : hash)
    {
        for(auto myVecEle : details.second)
        {
            ans += myVecEle ;
            ans += " " ;
        }
    }
    ans.pop_back() ;
    ans[0] = toupper(ans[0]) ;
    return ans ;
}
