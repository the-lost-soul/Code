void deleteAlt(struct Node *head)
{
    if(head and head->next)
    {
        // The list after the node to be deleted currently .
        struct Node* nextList = head->next->next ;
        struct Node* reqNode = head->next ;
        head->next = nextList ; 
        delete(reqNode) ;
        deleteAlt(nextList) ;
    }
}
