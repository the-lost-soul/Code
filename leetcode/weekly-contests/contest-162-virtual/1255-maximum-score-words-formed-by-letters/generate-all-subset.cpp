class Solution {
    int hash[26] = {} ;
    vector<int>score ;
    vector<bool>taken ;
    int maxScore = INT_MIN ;
public:
    int maxScoreWords(vector<string>& words, vector<char>& letters, vector<int>& score) ;
    void generateCombination(vector<string>& words , int len) ;
    void updateScore(vector<string>& words) ;
};
void Solution :: updateScore(vector<string>& words)
{
    int currScore = 0 ;
    vector<int>freq(26 , 0) ;
    for(int i = 0 ; i < words.size() ; i++)
    {
        if(taken[i])
        {
            for(auto ele : words[i])
            {
                currScore += score[ele - 'a'] ;
                freq[ele - 'a']++ ;
                if(freq[ele - 'a'] > hash[ele - 'a'])
                    return ;
            }
        }
    }
    maxScore = max(maxScore , currScore) ;
}
void Solution :: generateCombination(vector<string>& words , int len)
{
    if(len < 0)
    {
        updateScore(words) ;
        return ;
    }
    
    taken[len] = true ;
    generateCombination(words , len - 1) ;
    taken[len] = false ;
    generateCombination(words , len - 1) ;
}

int Solution :: maxScoreWords(vector<string>& words , vector<char>& letters , vector<int>&score)
{
    this->score = score ;
    taken.resize(words.size() , false) ;
    for(auto ele : letters)
        hash[ele - 'a']++ ;
    
    generateCombination(words , words.size() - 1) ;
    return maxScore ;
    
}
