/*
Method 2 (Use two pointers) 
Maintain two pointers – reference pointer and main pointer. Initialize both reference and main pointers to head. 
First move reference pointer to n nodes from head. Now move both pointers one by one until reference pointer reaches end. 
Now main pointer will point to nth node from the end. Return main pointer.
*/

//MY APPROACH
int getNthFromLast(Node *head, int n)
{
    // Your code here
    Node *temp=head;
    int count=0;
    while(temp!=NULL)
    {
        temp=temp->next;
        count++;
    }
    if(n>count)
    {
        return -1;
    }
    else
    {
        n=count-n;
        while(n--)
        {
            head=head->next;
        }
        return head->data;
    }
}

