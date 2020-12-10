void removeTheLoop(Node *node)
{
     unordered_set<Node *>node_address;
     Node *temp=new Node;temp=node;
     Node *prevOftemp=new Node;prevOftemp=NULL;
     while(temp->next!=NULL)
     {
         if(node_address.find(temp)==node_address.end())
         {
             //list_data.insert(make_pair(traversal_variable->data,traversal_variable))
             node_address.insert(temp);
             prevOftemp=temp;
             temp->next=temp;
         }
         else
         {
             prevOftemp->next=NULL;
             break;
         }
     }
     
}


