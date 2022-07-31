class Solution {
public:
    vector<int> processQueries(vector<int>& queries, int m) ;
    int linearSearch(int num , vector<int> permutation) ;
};
int Solution :: linearSearch(int num , vector<int> permutation)
{
    for(int i = 0 ; i < permutation.size() ; i++)
    {
        if(permutation[i] == num)
            return i ;
    }
    return -1 ;
}

vector<int> Solution :: processQueries(vector<int>& queries , int m)
{
    vector<int>permutation ;
    for(int i = 1 ; i <= m ; i++)
        permutation.push_back(i) ;
    
    vector<int>ans ;
    for(auto q : queries)
    {
        int ind = linearSearch(q , permutation) ;
        ans.push_back(ind) ;
        for(int i = ind - 1 ; i >= 0 ; i--)
        {
            swap(permutation[i] , permutation[i + 1]) ;
        }
    }
    return ans ;
}
