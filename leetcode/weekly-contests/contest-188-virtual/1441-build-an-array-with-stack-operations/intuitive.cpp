class Solution {
public:
    vector<string> buildArray(vector<int>& target, int n) ;
};

vector<string> Solution :: buildArray(vector<int>& target , int n)
{
    vector<string>res ;
    int currPos = 0 ;
    for(int num = 1 ; num <= n ; num++)
    {
        if(currPos >= target.size())
            break ;
        if(num == target[currPos])
        {
            res.push_back("Push") ;
            currPos++ ;
        }
        else
        {
            res.push_back("Push") ;
            res.push_back("Pop") ;
        }
    }
    return res ;
}
