/*Linked list Node structure

struct Node
{
	int data;
	Node* next;
	
	Node(int x){
	    data = x;
	    next = NULL;
	}
	
};
*/ 

/* arr[] is an array of pointers to heads of linked lists
 * and N is size of arr[]  
 */
Node* mergeList(Node* list1 , Node* list2)
{
    if(!list1)return list2 ;
    if(!list2)return list1 ;
    Node* result ;
    if(list1->data >= list2->data)
    {
        result = list2 ;
        result->next = mergeList(list1 , list2->next) ;
    }
    else
    {
        result = list1 ;
        result->next = mergeList(list1->next , list2) ;
    }
    return result ;
}
 
typedef pair<int , Node*> pairs ;
Node * mergeKLists(Node *arr[], int N)
{
    int end = N - 1 ;
    while(end != 0)
    {
        int left = 0 , right = end ;
        while(left < right)
        {
            arr[left] = mergeList(arr[left] , arr[right]) ;
            left++ ;
            right-- ;
            if(left >= right)
            {
                end = right ;
            }
        }
    }
    return arr[0] ;
}
