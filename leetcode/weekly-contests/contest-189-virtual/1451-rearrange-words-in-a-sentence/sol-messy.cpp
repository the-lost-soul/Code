class Solution {
public:
    string arrangeWords(string text) ;
};

string Solution :: arrangeWords(string text)
{
    map<int , vector<string>>hash ;
    int i = 0 , len = text.size() ;
    int totalWords = 0 ;
    string convertToSmall ;
    while(i < len)
    {
        string word = "" ;
        int wLen = 0 ;
        while(i < len and text[i] != ' ')
        {
            word += text[i] ;
            wLen++ ;
            i++ ;
        }
        totalWords++ ;
        if(totalWords == 1)
        {
            convertToSmall = word ;
        }
        if(hash.find(wLen) == hash.end())
        {
            hash[wLen] = vector<string>() ;
        }
        hash[wLen].push_back(word) ;
        i++ ;
    }
    string ans = "" ;
    int currNumWord = 0 ;
    for(auto ele : hash)
    {
        vector<string>words = ele.second ;
        for(auto w : words)
        {
            if(convertToSmall == w and currNumWord != 0)
            {
                w[0] = tolower(w[0]) ;
            }
            else if(currNumWord == 0)
            {
                w[0] = toupper(w[0]) ;
            }
            ans += w ;
            currNumWord++ ;
            if(currNumWord < totalWords)
                ans += " " ;
            
        } 
    }
    
    return ans ;
}
