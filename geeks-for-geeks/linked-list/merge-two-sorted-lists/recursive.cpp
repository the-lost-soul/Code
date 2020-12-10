
/*Please note that it's Function problem i.e.
you need to write your solution in the form of Function(s) only.
Driver Code to call/invoke your function is mentioned above.*/

/* Link list Node  
struct Node {
    int data;
    Node* next;
}; */
Node* SortedMerge(Node* head1,   Node* head2)
{
    /* This solution takes extra space 
     * But we can make it without using 
     * extra space ,FOR THIS REFER GEEKS FOR GEEKS
     * ARTICLE-->> SORTED MERGE IN PLACE*/
     
    // if any one linked list is empty
    if(head1==NULL)return head2;
    if(head2==NULL)return head1;
    
    // Stores the result i.e the head
    // of the list whose value is smaller
    Node *result;
    
    // If value of first list is 
    // greater than second list
    if(head1->data>head2->data)
    {
        result=head2;
        result->next=SortedMerge(head1,head2->next);
    }
    // If value of second list is
    // greater than first list
    else
    {
        result=head1;
        result->next=SortedMerge(head1->next,head2);
    }
    return result;
}
