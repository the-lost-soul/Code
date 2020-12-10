/* The method push to push element into the stack 2 */
void twoStacks :: push1(int x)
{
    // push element to stack1 if there is an empty
    // slot in array .
    if(top1 < top2)
    {
        top1 ++ ;
        arr[top1] = x ;
    }
}
   
/* The method push to push element into the stack 2*/
void twoStacks ::push2(int x)
{
    // push element to stack2 if there is an empty slot
    // in array .
    if(top1 < top2)
    {
        top2 -- ;
        arr[top2] = x ;
    }
}
   
/* The method pop to pop element from the stack 1 */
//Return the popped element
int twoStacks ::pop1()
{
    // If stack1 is not empty , then return the
    // top1 element , else return -1 .
    if(top1 > -1)
    {
        int temp = arr[top1] ;
        top1 -- ;
        return temp ;
    }
    return - 1 ;
}
/* The method pop to pop element from the stack 2 */
//Return the popped element
int twoStacks :: pop2()
{
    // If stack2 is not empty , then return top2
    // element , else return -1 .
    if(top2 < size)
    {
        int temp = arr[top2] ;
        top2 ++ ;
        return temp ;
    }
    return - 1 ;
}
