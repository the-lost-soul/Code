class Solution {
public:
    vector<string> findAndReplacePattern(vector<string>& words, string pattern) ;
};

vector<string> Solution :: findAndReplacePattern(vector<string>& words , string pattern)
{
    vector<string>res ;
    vector<char>replacePatt , replaceWord ;
    bool notMatch = false ;
    for(auto w : words)
    {
        notMatch = false ;
        replacePatt.assign(26 , '\0') ;
        replaceWord.assign(26 , '\0') ;
        for(int i = 0 ; i < w.length() ; i++)
        {
            int ind1 = pattern[i] - 'a' ;
            int ind2 = w[i] - 'a' ;
            if(replacePatt[ind1] == '\0' and replaceWord[ind2] == '\0')
            {
                replacePatt[ind1] = w[i] ;
                replaceWord[ind2] = pattern[i] ;
            }
            else if(replacePatt[ind1] != w[i] or replaceWord[ind2] != pattern[i])
            {
                notMatch = true ;
                break ;
            }
        }
        if(!notMatch)
        {
            res.push_back(w) ;
        }
    }
    return res ;
}
