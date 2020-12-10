int getMiddle(Node *head)
{
    
    if(head==NULL)
        return -1;
        
    int count=0;
    vector<int>data;
    Node *temp=head;
    while(temp!=NULL)
    {
        data.push_back(temp->data);
        count++;
        temp=temp->next;
    }
    return data[count/2];
}
