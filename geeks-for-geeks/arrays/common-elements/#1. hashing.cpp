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
vector<int>solve(vector<int>&vec1 , vector<int>&vec2 , vector<int>&vec3)
{
    map<int , int>hash = {} ;
    for(auto ele : vec1)
    {
        // By this if condition , we removed the duplicates present
        // in the first vector
        if(hash.find(ele) == hash.end())
        {
            hash[ele]++ ;
        }
    }
    
    for(auto ele : vec2)
    {
        // We check whether we have seen the current element in first vector
        // or not . If yes , then we check whether the count of that element
        // is 1 or not . If 1 , then increment the count by 1 .
        if(hash.find(ele) != hash.end() and hash[ele] == 1)
        {
            hash[ele]++ ;
        }
    }
    
    // Here also , we do similar to what we did for vector2 .
    for(auto ele : vec3)
    {
        if(hash.find(ele) != hash.end() and hash[ele] == 2)
        {
            hash[ele]++ ;
        }
    }
    
    vector<int>ans ;
    for(auto ele : hash)
    {
        if(ele.second == 3)
        {
            ans.push_back(ele.first) ;
        }
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
