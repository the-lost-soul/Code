#include<bits/stdc++.h>
#include<iostream>
using namespace std;
/* Convert decimal to base-62 */
string convertToShortURL(int id)
{
    int base = 62 ;
    char digit[63] = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789" ;
    string answer ;
    int remaind = 0 ;
    while(id)
    {
        remaind = id%62 ;
        id /= 62 ;
        answer += digit[remaind] ;
    }
    reverse(answer.begin() , answer.end()) ;
    return answer ;
}
/* Convert from base-62 to decimal */
int convertToID(string answer)
{
    int id = 0 ;
    for(int i = 0 ; i < answer.length() ; i++)
    {
        if(answer[i] >= 'a' and answer[i] <= 'z')id = id*62 + answer[i] - 'a' ;
        else if(answer[i] >= 'A' and answer[i] <= 'Z')id = id*62 + answer[i] - 'A' + 26 ;
        else if(answer[i] >= '0' and answer[i] <= '9')id = id*62 + answer[i] - '0' + 52 ;
    }
    return id ;
}
void solve(int id)
{
    string answer = convertToShortURL(id) ;
    int ID = convertToID(answer) ;
    cout<<answer<<endl<<ID<<endl ;
}
int main()
 {
	int testcase ;
	cin >> testcase ;
	while(testcase--)
	{
	    int id ;
	    cin >> id ;
	    solve(id) ;
	}
	return 0;
}
