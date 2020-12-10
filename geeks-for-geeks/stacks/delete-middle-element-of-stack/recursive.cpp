void deleteMidUtil(stack<int>& s , int size , int count)
{
    if(s.empty() or size == count)return ;
    int temp = s.top() ;
    s.pop() ;
    deleteMidUtil(s , size , count + 1) ;
    if(count != size/2)s.push(temp) ;
}
stack<int> deleteMid(stack<int>s , int size , int current)
{
    deleteMidUtil(s , size , current) ;
    return s ;
}
