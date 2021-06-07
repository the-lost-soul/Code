class Solution {
public:
    vector<int> numSmallerByFrequency(vector<string>& queries, vector<string>& words) ;
   int eachStringSmallestFreq(string& myVec) ;
};


int Solution :: eachStringSmallestFreq(string& s)
{
    int hash[26] ;
    memset(hash , 0 , sizeof(hash)) ;
    for(auto chars : s)
    {
        hash[chars - 'a']++ ;
    }
    for(auto alpha : hash)
    {
        if(alpha != 0)
        {
            return alpha ;
        }
    }  
    return 0 ;
}

vector<int> Solution :: numSmallerByFrequency(vector<string>& queries , vector<string>& words)
{
    vector<int>freq(11 , 0) ;
    for(auto word : words)
        freq[eachStringSmallestFreq(word)]++ ;
    
    for(int i = 1 ; i < 11 ; i++)
        freq[i] += freq[i - 1] ;
        
    vector<int>res ;
    for(auto s : queries)
    {
        int count = eachStringSmallestFreq(s) ;
        res.push_back(abs(freq[count] - freq[10])) ;
    }
    return res ;
}
