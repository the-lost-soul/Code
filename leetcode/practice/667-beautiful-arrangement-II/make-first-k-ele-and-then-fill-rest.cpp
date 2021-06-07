class Solution {
public:
    vector<int> constructArray(int n, int k) ;
};

vector<int> Solution :: constructArray(int n , int k)
{
    bool add = true ;
    vector<int>res(n , 0) ;
    res[0] = 1 ;
    int maxEle = 1 , i = 1 ;
    /* The idea here is to first make an array of size k
     * with difference between each adjacent pair as following
     * | a1 - a2 | = k , |a2 - a3 | = k - 1 , | a3 - a4 | = k - 2
     * and so on till k doesn't become zero .
     */
    while(i < n)
    {
        res[i] = res[i - 1] + (add ? k : -k) ;
        add = add ? false : true ;
        maxEle = res[i] > maxEle ? res[i] : maxEle ;
        k-- ;
        i++ ;
        if(k == 0) break ;
    }
    /* Now fill the remaining array . Before , fillinf the
     * array increment maxEle by 1 as the current maxEle has 
     * already been used .
     */
    maxEle++ ;
    while(i < n)
    {
        res[i++] = maxEle++ ;        
    }
    return res ;
}
