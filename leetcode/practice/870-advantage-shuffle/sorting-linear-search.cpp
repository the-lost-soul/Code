class Solution {
public:
    vector<int> advantageCount(vector<int>& A, vector<int>& B) ;
    int linearSearch(vector<int>& arr , multiset<int>& included , int ele) ;
};

int Solution :: linearSearch(vector<int>& arr , multiset<int>& included , int ele)
{
    
    for(int i = 0 ; i < size(arr) ; i++)
    {
        if(arr[i] > ele)
        {
            auto itr = included.find(arr[i]) ;
            if(itr != included.end())
            {
                included.erase(itr) ;
                return i ;
            }
        }
    }
    return -1 ;
}

vector<int> Solution :: advantageCount(vector<int>& arr1 , vector<int>& arr2)
{
    multiset<int>included(begin(arr1) , end(arr1)) ;
    sort(begin(arr1) , end(arr1)) ;
    vector<int>res(size(arr1) , -1) ;
    for(int i = 0 ; i < size(arr2) ; i++)
    {
        int ind = linearSearch(arr1 , included , arr2[i]) ;
        if(ind != -1)
        {
            res[i] = arr1[ind] ;
        }
    }
    
    for(int i = 0 ; i < size(arr1) ; i++)
    {
        if(res[i] == -1)
        {
            auto itr = included.begin() ;
            res[i] = *itr ;
            included.erase(itr) ;
        }
    }
    return res ;
}
