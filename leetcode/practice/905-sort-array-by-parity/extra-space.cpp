class Solution {
public:
    vector<int> sortArrayByParity(vector<int>& arr) ;
};

vector<int> Solution :: sortArrayByParity(vector<int>& arr)
{
    vector<int>vec ;
    int start = 0 ;
    for(int i = 0 ; i < arr.size() ; i++)
    {
        // Push all the odd elements to a temp vector
        // and assign the even elements at it's correct
        // position from front .
        if(arr[i]%2 != 0)vec.push_back(arr[i]) ;
        else
        {
            arr[start] = arr[i] ;
            start ++ ;
        }
    }
    
    // Assign the odd elements of temp vector to desired
    // vector .
    int i = 0 ;
    while(start != arr.size())
    {
        arr[start] = vec[i] ;
        start ++ ;
        i ++ ;
    }
    return arr ;
}
