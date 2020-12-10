// LOGIC-->>TWO POINTER TECHNIQUE
// WHEN FAST WILL REACH END THEN SLOW
// POINTER WILL BE POINTING TO MIDDLE ELEMENT

Node* insertInMiddle(Node* head, int x)
{
    // Cpde here
    Node *slow=head;
    Node *fast=head->next;
    while(fast && fast->next)
    {
        slow=slow->next;
        fast=fast->next->next;
        
    }
    
    Node *addValue=new Node;
    addValue->data=x;
    addValue->next=slow->next;
    slow->next=addValue;
    return head;
}
