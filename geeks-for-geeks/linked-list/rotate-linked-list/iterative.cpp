void rotate(struct node **head_ref , int k)
{
   
    struct node *current = (struct node *)malloc(sizeof(struct node)) ;
    current = *head_ref ;


    // CONTAINS THE ADDRESS OF  current->next NODE
    struct node *nextOfK = (struct node *)malloc(sizeof(struct node)) ;   
    nextOfK = NULL ;


    // Contains address of previous of current node
    struct node *current_prev = (struct node *)malloc(sizeof(struct node)) ;   
    current_prev = NULL ;

    int count = 0 ;

    // If this is 1 then we are at last element and so no need to do anything
    int check = 0 ;   

    while(current != NULL)
    {
        current_prev = current ;
        current = (current)->next ;
        count++ ;
        if(count == k && current != NULL)
        {
            nextOfK = current ;
            (current_prev)->next = NULL ;
            check = 1 ;
        }
           
    }
    if(check == 1)
    {
        (current_prev)->next = *head_ref ;
        *head_ref = nextOfK ;
    }
   
   
}

