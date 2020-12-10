void revUtil(queue<long long int>& q)
{
    if(q.empty())return ;
    long long int temp = q.front() ;
    q.pop() ;
    revUtil(q) ;
    q.push(temp) ;
}
/* Apply same logic as that of reversing a stack */
queue<long long int> rev(queue<long long int> q)
{
    revUtil(q) ;
    return q ;
    
}
