class RLEIterator {
public:
    int lastIndUsed , len ;
    vector<int>encoded ;
    RLEIterator(vector<int>& arr) ;
    int next(int n) ;
};

/**
 * Your RLEIterator object will be instantiated and called as such:
 * RLEIterator* obj = new RLEIterator(A);
 * int param_1 = obj->next(n);
 */

RLEIterator :: RLEIterator(vector<int>& arr)
{
    lastIndUsed = 0 , len = arr.size() ;
    encoded = arr ;
}

int RLEIterator :: next(int n)
{
    int res = -1 ;
    while(n > 0 and lastIndUsed < len)
    {
        int key = encoded[lastIndUsed + 1] ;
        int count =  encoded[lastIndUsed];
        res = key ;
        if(count == 0)
        {
            lastIndUsed += 2 ;
            continue ;
        }
        // If the current index gets exhausted fully , then we will
        // check whether next index can get exhausted or not . If not
        // return -1 
        if(count - n < 0)
        {
            lastIndUsed += 2 ;
            n -= count ;
            if(lastIndUsed >= len)return -1 ;
        }
        // If current index gets exhausted fully i.e number of ele == n ,
        // then move the index ahead so as to exhaust next element in upcoming
        // function call .
        else if(count - n == 0)
        {
            lastIndUsed += 2 ;
            n = 0 ;
        }
        // If current element doesn't gets exhausted fully , then no need
        // to move ahead as this same element can be exhausted in next function
        // call too .
        else
        {
            encoded[lastIndUsed] = count - n ;
            n = 0 ;
        }
    }
    return res ;
}
