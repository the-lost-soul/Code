class Solution {
public:
    vector<vector<string>> suggestedProducts(vector<string>& products, string searchWord) ;
};


vector<vector<string>> Solution :: suggestedProducts(vector<string>& products , string searchWord)
{
    sort(products.begin() , products.end()) ;
    vector<string> :: iterator index = products.begin() ;
    string word = "" ;
    vector<vector<string>> ans ;
    for(char ele : searchWord)
    {
        word += ele ;
        index = lower_bound(products.begin() , products.end() , word) ;
        vector<string>suggested ;
        for(int i = 0 ; i < 3 and index + i != products.end() ; i++)
        {
            string s = *(index + i) ;
            if(s.find(word) == string :: npos)break ;
            suggested.push_back(s) ;
        }
        ans.push_back(suggested) ;
    }
    
    return ans ;
}
