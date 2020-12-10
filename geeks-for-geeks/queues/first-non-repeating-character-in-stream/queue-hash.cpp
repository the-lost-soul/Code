#include<bits/stdc++.h>
#include<iostream>
using namespace std;
void scanArray(vector<char>& stream , int size)
{
    stream.resize(size) ;
    for(int i = 0 ; i < size ; i++)
        cin >> stream[i] ;
}
void solve(vector<char>& stream)
{
    unordered_map<char , int>hash ;
    queue<char>myQueue ;
    for(int i = 0 ; i < stream.size() ; i++)
    {
        if(hash.find(stream[i]) == hash.end())
        {
            hash[stream[i]]++ ;
            myQueue.push(stream[i]) ;
            cout << myQueue.front() << " " ;
        }
        else
        {
            queue<char>temp ;
            while(!myQueue.empty())
            {
                char ch = myQueue.front() ;
                myQueue.pop() ;
                if(ch != stream[i])
                    temp.push(ch) ;
                
            }
            while(!temp.empty())
            {
                char ch = temp.front() ;
                temp.pop() ;
                myQueue.push(ch) ;
            }
            if(myQueue.empty())
            {
                cout << "-1 " ;
            }
            else cout << myQueue.front() << " " ;
        }
    }
    cout << endl ;
}
int main()
 {
	int testcase ;
	cin >> testcase ;
	while(testcase--)
	{
	    int size ;
    	cin >> size ;
    	vector<char>stream ;
    	scanArray(stream , size) ;
	    solve(stream) ;
	}
	return 0;
}
