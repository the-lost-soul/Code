void sortUtil(int temp , stack<int>&s)
{
    if(s.empty() or temp > s.top())s.push(temp) ;
    else
    {
        int ele = s.top() ;
        s.pop() ;
        sortUtil(temp , s) ;
        s.push(ele) ;
    }
}
/* The idea is to pop all the elements one by one
 * till the stack becomes empty and then push each
 * element in sorted order . Now , question arises 
 * how to again push element in sorted order ? The
 * answer is to check -- 
 * 1--> If stack is empty or not , if yes then push
 *   the element and if not then check whether top
 *   of stack is smaller than the element to be pushed
 *   or not , if element to be pushed is larger then
 *   push the element .
 *   If element to be pushed is smaller than top element
 *   of stack  then again call the sub-routine "sortUtil"
 *   until either the stack becomes empty or top of stack
 *   becomes smaller than element to be pushed .
*/
void SortedStack :: sort()
{
    int temp ;
    if(!s.empty())
    {
        temp = s.top() ;
        s.pop() ;
        sort() ;
        sortUtil(temp , s) ;
    }
}
