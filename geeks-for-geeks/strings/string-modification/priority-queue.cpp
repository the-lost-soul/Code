struct key
{
    char ele ;
    int freq ;
    
    bool operator<(const key &k1) const
    {
        return freq < k1.freq ;
    }
} ;
string rearrangeString(string str)
{
    int count[26] = {0} ;
    for(int i = 0 ; i < str.length() ; i++)count[str[i] - 'a']++ ;
    priority_queue<key>maxHeap ;
    for(char i = 'a' ; i <= 'z' ; i++)
        if(count[i - 'a'] > 0)
            maxHeap.push(key{i , count[i - 'a']}) ;
    
    key prev{'#' , -1} ;
    str = "" ;
    while(!maxHeap.empty())
    {
        key curr = maxHeap.top() ;
        maxHeap.pop() ;
        str += curr.ele ;
        if(prev.freq > 0)maxHeap.push(prev) ;
        (curr.freq)-- ;
        prev = curr ;
    }
    return str ;
}
