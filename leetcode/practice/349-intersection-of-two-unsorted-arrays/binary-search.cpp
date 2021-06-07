class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) ;
};

vector<int> Solution :: intersection(vector<int>& arr1 , vector<int>& arr2)
{
    sort(arr1.begin() , arr1.end()) ;
    sort(arr2.begin() , arr2.end()) ;
    vector<int>ans ;
    for(int i = 0 ; i < arr1.size() ; i++)
    {
        // Neglect all duplicates .
        while(i < arr1.size() - 1 and arr1[i] == arr1[i+1])i++ ;
        // Do search .
        if(binary_search(arr2.begin() , arr2.end() , arr1[i]))
            ans.push_back(arr1[i]) ;
            
    }
    return ans ;
}
