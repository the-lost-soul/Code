Node* segregate(Node *head) 
{
    int ones = 0 , zeroes = 0 ,twos = 0 ;
    Node * temp = head ;
    while(temp)
    {
        if(temp->data == 0)zeroes++ ;
        else if(temp->data == 1)ones++ ;
        else if(temp->data == 2)twos++ ;
        temp = temp->next ;
    }
    temp = head ;
    while(temp)
    {
        while(zeroes --)
        {
            temp->data = 0 ;
            temp = temp->next ;
        }
        while(ones--)
        {
            temp->data = 1 ;
            temp = temp->next ;
        }
        while(twos --)
        {
            temp->data = 2 ;
            temp = temp->next ;
        }
    }
    return head ;
}
