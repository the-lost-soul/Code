class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) ;
};

vector<int> Solution :: intersect(vector<int>& arr1 , vector<int>& arr2)
{
    int len1 = arr1.size() , len2 = arr2.size() ;
    sort(arr1.begin() , arr1.end()) ;
    sort(arr2.begin() , arr2.end()) ;
    vector<int>ans ;
    int i = 0 , j = 0 ;
    while(i < len1 and j < len2)
    {
        if(arr1[i] == arr2[j])
        {
            ans.push_back(arr1[i]) ;
            i++ ;
            j++ ;
        }
        else if(arr1[i] > arr2[j])
        {
            j++ ;
        }
        else i++ ;
    }
    return ans ;
}
