class Solution
{
public:
    string mostCommonWord(string paragraph, vector<string>& banned)
    {
        unordered_set<string>bannedHash ;
        for(auto ele : banned)
            bannedHash.insert(ele) ;


        unordered_map<string , int>hash ;
        string word = "" , ans = "" ;
        int count = INT_MIN ;
        for(int i = 0 ; i < paragraph.length() ; i++)
        {
            char ch = paragraph[i] ;
            if(islower(ch) or isupper(ch))
                word += ch ;

            if(word != "" and (ch == '?' or ch == '.' or ch == '!' or ch == ',' or ch == '"' or ch == ';' or ch == ' ' or i == paragraph.length() - 1))
            {
                transform(word.begin() , word.end() , word.begin() , ::tolower) ;
                if(bannedHash.find(word) == bannedHash.end())
                    hash[word]++ ;

                if(hash[word] > count)
                {
                    ans = word ;
                    count = hash[word] ;
                }
                word = "" ;
            }
        }

        return ans ;
    }
};
