class Solution {
public:
    vector<int> numSmallerByFrequency(vector<string>& queries, vector<string>& words) ;
    vector<int> eachStringSmallestFreq(vector<string>& myVec) ;
    int binary_search(vector<int>& smallestInWords , int count , int left , int right) ;
};

int Solution :: binary_search(vector<int>& smallestInWords , int count , int left , int right)
{
    while(left <= right)
    {
        int mid = (left + right)/2 ;
        if(smallestInWords[mid] <= count)
            left = mid + 1 ;
        else
            right = mid - 1 ;
    }
    return left ;
}
vector<int> Solution :: eachStringSmallestFreq(vector<string>& myVec)
{
    int hash[26] ;
    vector<int>smallestInStrings ;
    for(auto ele : myVec)
    {
        memset(hash , 0 , sizeof(hash)) ;
        for(auto chars : ele)
        {
            hash[chars - 'a']++ ;
        }
        for(auto alpha : hash)
        {
            if(alpha != 0)
            {
                smallestInStrings.push_back(alpha) ;
                break ;
            }
        }  
    }
    return smallestInStrings ;
}

vector<int> Solution :: numSmallerByFrequency(vector<string>& queries , vector<string>& words)
{
    
    vector<int>smallestInWords = eachStringSmallestFreq(words) ;
    vector<int>smallestInQueries = eachStringSmallestFreq(queries) ;
    sort(smallestInWords.begin() , smallestInWords.end()) ;
    
    vector<int>res ;
    for(auto count : smallestInQueries)
    {
        int left = 0 , right = smallestInWords.size() - 1 ;
        int index = binary_search(smallestInWords , count , left , right) ;
        res.push_back(right - index + 1) ;
    }
    return res ;
}
