#include<bits/stdc++.h>
#include<iostream>
using namespace std;

int precedence(char ch)
{
    if(ch == ')' or ch == '(')return -1 ;
    if(ch == '+' or ch == '-')return 1 ;
    if(ch == '*' or ch == '/')return 2 ;
    return 3 ;
}

string solve(string infix)
{
    int len = infix.length() ;
    string postfix = "" ;
    stack<char>s ;
    for(int i = 0 ; i < len ; i++)
    {
        if(infix[i] >= 'a' and infix[i] <= 'z') postfix += infix[i] ;
        else
        {
            if(infix[i] == '(')s.push(infix[i]) ;
            else if(infix[i] == ')')
            {
                while(!s.empty() and s.top() != '(')
                {
                    if(s.top() != ')' or s.top() != '(')
                        postfix += s.top() ;
                    s.pop() ;
                    if(!s.empty() and s.top() == '(')
                    {
                        s.pop() ;
                        break ;
                    }
                }
            }
            else
            {
                while(!s.empty() and (precedence(s.top()) >= precedence(infix[i])))
                {
                    if(s.top() == '(')break ;
                    postfix += s.top() ;
                    s.pop() ;
                }
                s.push(infix[i]) ;
            }
        }
    }
    while(!s.empty())
    {
        if(s.top() != '(' and s.top() != ')')
            postfix += s.top() ;
        s.pop() ;
    }
    return postfix ;
}
int main()
 {
	int testcase ;
	cin >> testcase ;
	while(testcase--)
	{
	    string infix ;
	    cin >> infix ;
	    cout << solve(infix) << endl ;
	}
	return 0;
}
