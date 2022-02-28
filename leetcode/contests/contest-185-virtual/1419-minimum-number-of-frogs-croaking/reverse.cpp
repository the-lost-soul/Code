class Solution {
public:
    int minNumberOfFrogs(string croakOfFrogs) ;
};

int Solution :: minNumberOfFrogs(string croakOfFrogs)
{
    reverse(begin(croakOfFrogs) , end(croakOfFrogs)) ;
    vector<char> croak = {'c' , 'r' , 'o' , 'a' , 'k'} ;
    unordered_map<char , int>freq ;
    int ans = INT_MIN ;
    for(auto ch : croakOfFrogs)
    {
        bool legal = false ;
        for(auto ele : croak)
            if(ele == ch)
                legal = true ;
        if(not legal) return -1 ;
        if(ch != 'c')
        {
            freq[ch]++ ;
            continue ;
        }
        for(auto ele : croak)
            if(ele != 'c')
                if(freq[ele] == 0)
                    return -1 ;
        for(auto ele : croak)
        {
            if(ele == 'c') continue ;
            ans = max(ans , freq[ele]) ;
            freq[ele]-- ;
        }
    }
    
    for(auto ele : croak)
    {
        if(freq[ele] > 0)return -1 ;
    }
    return ans ;
}    
