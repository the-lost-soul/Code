Node* deleteAllOccurances(Node *head , int x)
{
    if(head == NULL)return NULL ;
    Node *next = NULL ;
    while(head->data == x && head != NULL)
    {
        next = head->next ;
        delete head ;
        head = next ;
    }
    if(head != NULL)head->next = deleteAllOccurances(head->next , x) ;
    return head ;
}


