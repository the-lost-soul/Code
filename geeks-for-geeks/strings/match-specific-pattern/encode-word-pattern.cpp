vector<string>encodeDictAndFindWords(vector<string>dict , string encodedPatt)
{
    vector<string>encode ;
    int len = dict.size() ;
    // For every word present in dictionary .
    for(int i = 0 ; i < len ; i++)
    {
        // Encode the current word on basis of count of occurrence
        // of each character of the word .
        string encodedWord = "" ;
        string currWord = dict[i] ;
        int lenCurrWord = currWord.length() ;
        int j = 0 ;
        while(j < lenCurrWord)
        {
            int count = 1 ;
            while(j < lenCurrWord - 1 and currWord[j] == currWord[j + 1])
            {
                count++ ;
                j++ ;
            }
            j++ ;
            encodedWord += to_string(count) ;
        }
        // If the encoded word is same as that of encoded string , then
        // add it to vector .
        if(encodedPatt == encodedWord)encode.push_back(currWord) ;
    }
    return encode ;
}
vector<string>findMatchedWords(vector<string>dict , string pattern)
{
    /* Encode the pattern in form of occurrences of each 
     * character .
     * Eg. -- abb will be encoded as 12
              aaa will be encoded as 3 .
     *        abc will be encoded as 111
     */
    string encodedPatt = "" ;
    int lenPatt = pattern.length() ;
    int i = 0 ;
    while(i < lenPatt)
    {
        int count = 1 ;
        while(i < lenPatt - 1 and pattern[i] == pattern[i + 1])
        {
            count++ ;
            i++ ;
        }
        i++ ;
        encodedPatt += to_string(count) ;
    }
    // Get all the words from dictionary whose encoding is
    // same as that of the encoded pattern .
    vector<string>encode = encodeDictAndFindWords(dict , encodedPatt) ;
    return encode ;
}
