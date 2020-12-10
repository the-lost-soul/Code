#include<bits/stdc++.h>
#include<iostream>
using namespace std;
void scanArray(int arr[] , int size)
{
    for(int i = 0 ; i < size ; i++)
    cin >> arr[i] ;
}
void solve(int arr[] , int size)
{
    int sumOfNnumbers = (size*(size + 1))/2 ;
    // cout<<"sumOfNnumbers == "<<sumOfNnumbers<<endl ;
    int productOfNnumbers = 1 ;
    for(int i = 1 ; i <= size ; i++)productOfNnumbers *= i ;
    
    // cout<<"productOfNnumbers == "<<productOfNnumbers<<endl ;
    int sumOfNumInArray = 0 ;
    int productOfNumInArray = 1 ;
    for(int  i = 0 ; i < size ; i++)
    {
        sumOfNumInArray += arr[i] ;
        productOfNumInArray *= arr[i] ;
    }
    // cout<<"sumOfNumInArray == "<<sumOfNumInArray<<endl ;
    // cout<<"productOfNumInArray == "<<productOfNumInArray<<endl ;
    int diff = sumOfNnumbers - sumOfNumInArray ;
    // cout<<"dif == "<<diff<<endl ;
    float divide = (float)productOfNnumbers / (float)productOfNumInArray ;
    // cout<<"divide == "<<divide<<endl ;
    float constant = diff*divide ;
    // cout<<"constant == "<<constant<<endl ;
    
    float missing = (float)constant/(float)(divide - 1) , repeating = (diff)/(divide - 1) ;
    cout<<(int)repeating<<" "<<(int)missing<<endl ;
    
    
}
int main()
 {
	int testcase ;
	cin >> testcase ;
	
	// By this , you can check by how much integer overflow has
	// occurred .
	cout << INT_MAX - 2147483648 << endl;
	
	while(testcase--)
	{
	    int size ;
	    cin >> size ;
	    int arr[size] ;
	    scanArray(arr , size) ;
	    solve(arr , size) ;
	}
	return 0;
}
