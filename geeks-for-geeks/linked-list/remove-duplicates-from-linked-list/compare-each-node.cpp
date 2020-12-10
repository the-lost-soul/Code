Node *removeDuplicates(Node *root)
{
    //this variable is used to 
    //compare two values
    int compare=root->data;
    
    //used to store the address of the
    //variable compare
    Node *prev=root;
    
    //used to traverse the list
    Node *head=root->next;
    
   /*traverse the list till last node*/
   while(head!=NULL)
   {
       if(head->data==compare)
       {
           prev->next=head->next;
           free(head);
           head=prev->next;
       }
       
       //if no deletion then move ahead
       else
       {
           //stores value of next element which is
           //to be compared
           compare=head->data;
           //stores the address of Variable compare
           prev=head;
           //move pointer ahead
           head=head->next;
       }
   }
   return root;
    
}


