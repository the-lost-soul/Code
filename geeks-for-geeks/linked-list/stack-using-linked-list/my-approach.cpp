/* The method push to push element into the stack */
void Stack :: push(int x)
{
    StackNode *current = new StackNode ;
    current->data = x ;
    current->next = NULL ;
    
    // If stack is empty
    if(top == NULL)
    {
        top = current ;
    }
    // Add a new element at front
    // of list(STACK) and point top to it
    else
    {
        current->next = top ;
        top = current ;
    }
        
}
/*The method pop which return the element poped out of the stack*/
int Stack :: pop()
{
    // If stack is empty
    if(top == NULL)return -1 ;
       
    // If not empty then delete top
    // and make top point to next element
    struct StackNode *temp = top->next ;
    int x = top->data ;
    free(top);
    top = temp;
    return x ;
        
        
}


