#include<bits/stdc++.h>
#include<iostream>
using namespace std;
/* Use comaprison based sorting */
/* Good question to learn comparators*/
/* Take input in form of strings and moreover use reference
 * operator when calling the scanArray() otherwise changes may
 * not get reflected and may cause seg fault .
 */
void scanArray(vector<string> &arr , int size)
{
    int x ;
    for(int i = 0 ; i < size ; i++)
    {
        cin >> x ;
        arr.push_back(to_string(x)) ;
    }
}
bool comp(string a , string b)
{
    string a1 = a.append(b) ;
    string b1 = b.append(a) ;
    
    if(a1 > b1)return true ;
    return false ;
}
void solve(vector<string> arr , int size)
{
    sort(arr.begin() , arr.end() , comp) ;
    for(int i = 0 ; i < size ; i++)
    cout << arr[i] ;
    
    cout<<endl ;
}
int main()
 {
	int testcase ;
	cin >> testcase ;
	while(testcase--)
	{
	    int size ;
    	cin >> size ;
    	vector<string> arr ;
    	scanArray(arr , size) ;
	    solve(arr , size) ;
	}
	return 0;
}
