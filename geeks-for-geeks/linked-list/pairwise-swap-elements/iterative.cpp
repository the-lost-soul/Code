WE CAN ALSO CHANGE LINKS INSTEAD OF SWAPPING DATA 


void pairWiseSwap(struct node *head)
{
   // The task is to complete this method

   struct node *first=new struct node;//ALLOCATES NODE 

   struct node *second=new struct node;//ALLOCATES NODE

   first=head;
   second=head->next;

   int swap;//USED FOR SWAPPING first AND second

   while(second!=NULL)
   {
       swap=first->data;
       first->data=second->data;
       second->data=swap;

       //WE WILL STEP INSIDE if ONLY WHEN THERE WILL BE 
       //EVEN NODES i.e.  second->data!=null
       if(second->next!=NULL)
       {
           first=first->next->next;
           second=second->next->next;
       }

       //WHEN THERE WILL BE ODD NODES THEN AFTER SWAPPING
       //DATA OF EVEN NUMBER OF NODES WE WILL BREAK
       else break;
       
   }
}


