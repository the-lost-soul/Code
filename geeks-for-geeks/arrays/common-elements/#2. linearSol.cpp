#include<bits/stdc++.h>
#include<iostream>
using namespace std;
typedef struct
{
    int size1 , size2 , size3 ;
}size ;
void scanArray(vector<int>&vec1 , vector<int>&vec2 , vector<int>&vec3 , size vecSize)
{
    int ele ;
    for(int i = 0 ; i < vecSize.size1 ; i++)
    {
        ele = 0 ;
        cin >> ele ;
        vec1.push_back(ele) ;
        
    }
    
    for(int i = 0 ; i < vecSize.size2 ; i++)
    {
        ele = 0 ;
        cin >> ele ;
        vec2.push_back(ele) ;
    }
    
    for(int i = 0 ; i < vecSize.size3 ; i++)
    {
        ele = 0 ;
        cin >> ele ;
        vec3.push_back(ele) ;
    }
}
vector<int>solve(vector<int>&arr1 , vector<int>&arr2 , vector<int>&arr3)
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
void printAns(vector<int>ans)
{
    if(ans.size() == 0)cout << "-1" ;
    else
    {
        for(auto ele : ans)
            cout << ele << " " ;
    }
    cout << endl ;
}
int main()
 {
	int testcase ;
	cin >> testcase ;
	while(testcase--)
	{
	    size vecSize ;
    	cin >> vecSize.size1 >> vecSize.size2 >> vecSize.size3 ;
    	vector<int>vec1 , vec2 , vec3 ;
    	scanArray(vec1 , vec2 , vec3 , vecSize) ;
	    vector<int>ans = solve(vec1 , vec2 , vec3) ;
	    printAns(ans) ;
	}
	return 0;
}
