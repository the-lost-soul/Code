#include<bits/stdc++.h>
#include<iostream>
using namespace std;
/* The idea here is following -- 
 * 1--> If current direction is towards right , then 
 *      'L' will take us to direction "up" and 'R' will
 *      take us to direction "down" .
 * 2--> If current direction is towards left , then 
 *      'L' will take us to direction "down" and 'R' will
 *      take us to direction "up" .
 * 3--> If current direction is towards up , then 
 *      'L' will take us to direction "left" and 'R' will
 *      take us to direction "right" .
 * 4--> If current direction is towards down , then 
 *      'L' will take us to direction "right" and 'R' will
 *      take us to direction "left" .
 */
typedef struct
{
    int x = 0 ;
    int y = 0 ;
}coOrdinates ;
string solve(string str)
{
    int size = str.length() ;
    coOrdinates point ;
    // bool horizontal = true , vertical = false ;
    int up = 0 , right = 1 , down = 2 , left = 3 ;
    int dir = right ;
    for(int i = 0 ; i < size ; i++)
    {
        if(str[i] == 'G')
        {
            if(dir == right)point.x += 1 ;
            else if(dir == left)point.x -= 1 ;
            else if(dir == up)point.y += 1 ;
            else if(dir == down)point.y -= 1 ;
        }
        else if(str[i] == 'L')
        {
            dir = (4 + dir - 1)%4 ;
        }
        else
        {
            dir = (dir + 1)%4 ;
        }
    }
    if(point.x == 0 and point.y == 0)return "Circular" ;
    return "Not Circular" ;
}
int main()
 {
	int testcase ;
	cin >> testcase ;
	while(testcase--)
	{
	    string str ;
	    cin >> str ;
	    cout << solve(str) << endl ;
	}
	return 0;
}
