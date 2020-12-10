struct node* findIntersection(struct node* head1, struct node* head2)
{
    
    // Stores length of given linked lists
    int length1=0,length2=0;
    
    // Used while finding length of both lists
    struct node *head11=head1,*head22=head2;
    
    // Stores head of longer list and is used during 
    // insertion in defined set
    struct node *longListHead;
    
    // Stores head of shorter list and is used while deleting elements
    // already present in the defined set
    struct node *smallListHead;
    
    // Stores the element of the longer list in ascending order
    multiset<int>longestList;
    
    // Stores the intersection of both lists
    multiset<int>intersectionOfList;
    
    // This loop finds the length of both lists
    while(head11!=NULL || head22!=NULL)
    {
        if(head11!=NULL)
        {
            head11=head11->next;
            length1++;
        }
        if(head22!=NULL)
        {
            head22=head22->next;
            length2++;
        }
    }
 
    longListHead=length1>length2?head1:head2;
    smallListHead=length1>length2?head2:head1;

    // Insert the elements of longer list
    // to the multiset named longerList
    while(longListHead!=NULL)
    {
        longestList.insert(longListHead->data);
        longListHead=longListHead->next;

    }
    
    // Traverses the smaller linked list
    while(smallListHead!=NULL)
    {
        // This will insert the data into a multiset named intersection
        // of list and will delete that data from longestList multiset
        if(longestList.find(smallListHead->data)!=longestList.end())
        {
            set<int>::iterator it=longestList.find(smallListHead->data);
            longestList.erase(it);
            intersectionOfList.insert(smallListHead->data);
        }
        smallListHead=smallListHead->next;
    }
    
    
    // This for loop will make a new intersected linked list
    // with the help of the "intersectionOfList" MULTISET
    set<int>::iterator it;
    struct node *head=NULL,*prev=NULL;
    for(it=intersectionOfList.begin();it!=intersectionOfList.end();it++)
    {
        struct node *temp=new struct node;
        temp->data=*it;
        temp->next=NULL;
        if(head==NULL)
        {
            head=temp;
            prev=temp;
        }
        else
        {
            prev->next=temp;
            prev=temp;
        }
        
    }
    
    return head;
    
    
}


