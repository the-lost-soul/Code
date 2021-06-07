class Solution {
public:
    vector<int> arraysIntersection(vector<int>& arr1, vector<int>& arr2, vector<int>& arr3) ;
};

vector<int>Solution :: arraysIntersection(vector<int>& arr1, vector<int>& arr2, vector<int>& arr3)
{
    int i = 0 , j = 0 , k = 0 ;
    int len1 = arr1.size() , len2 = arr2.size() , len3 = arr3.size() ;
    vector<int>ans ;
    while(i < len1 and j < len2 and k < len3)
    {
        int firstEle = arr1[i] ;
        int secondEle = arr2[j] ;
        int thirdEle = arr3[k] ;
        if(firstEle == secondEle and secondEle == thirdEle)
        {
            ans.push_back(firstEle) ;
            i++ , j++ , k++ ;
        }
        else if(firstEle < secondEle)i++ ;
        else if(secondEle < thirdEle)j++ ;
        else k++ ;
    }
    return ans ;
}
