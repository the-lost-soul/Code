class Solution {
public:
    vector<int> advantageCount(vector<int>& A, vector<int>& B) ;
};

vector<int> Solution :: advantageCount(vector<int>& arr1 , vector<int>& arr2)
{
    multiset<int>included(begin(arr1) , end(arr1)) ;
    sort(begin(arr1) , end(arr1)) ;
    vector<int>res(size(arr1) , -1) ;
    for(int i = 0 ; i < size(arr2) ; i++)
    {
        auto itr = included.upper_bound(arr2[i]) ;
        if(itr != included.end())
        {
            res[i] = *itr ;
            included.erase(itr) ;
        }
        else
        {
            res[i] = *(included.begin()) ;
            included.erase(included.begin()) ;
        }
    }
    return res ;
}
