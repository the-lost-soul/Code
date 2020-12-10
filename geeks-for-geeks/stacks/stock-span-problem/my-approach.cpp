#include<bits/stdc++.h>
using namespace std;
/* Scan the stock for n days */
void scanStock(int days, int stock[])
{
    for(int i=0; i<days; i++)
    {
        cin>>stock[i];
    }
}
/* Find the span for each days */
int *findSpan(int days, int stock[], int span[])
{
    // For first day span is 1
    span[0]=1;
    
    // s1 is auxilliary stack which stores 
    // all the stock price graeter than ith day
    stack<int>s1;
    // Push it to s1
    s1.push(0);
    
    // Traverse for each day
    for(int i=1; i<days; i++)
    {
        span[i]=1;
        // compare the i'th stock price from the 
        // days before it which are stored in s1
        while(!s1.empty())
        {
            if(stock[i]>=stock[s1.top()])
            {
                span[i]+=span[s1.top()];
                s1.pop();
            }
            else break;
        }
        s1.push(i);
    }

}
void printAnswer(int span[], int days)
{
    for(int i=0; i<days; i++)
    {
        cout<<span[i]<<" ";
    }
}

int main() 
{
	int testcases;
	cin>>testcases;
	while(testcases--)
	{
	    // Stock for number of days
	    int days;
	    cin>>days;
	    
	    // Stores stack for n days and scns it
	    int stock[days];
	    scanStock(days, stock);
	    
	    // Stores span for each day
	    int span[days];
	    findSpan(days, stock, span);
	   
	    
	    // print answer
	    printAnswer(span, days);
	    cout<<endl;
	    
	}
	
	return 0;
}
