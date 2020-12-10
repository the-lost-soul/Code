void deleteAlt(struct Node *head)
{
    struct Node* tempHead = head ;
    while(tempHead and tempHead->next)
    {
        // The list after the node to be deleted currently .
        struct Node* nextList = tempHead->next->next ;
        // Node to be deleted .
        struct Node* reqNode = tempHead->next ;
        tempHead->next = nextList ; 
        delete(reqNode) ;
        tempHead = nextList ;
    }
}
