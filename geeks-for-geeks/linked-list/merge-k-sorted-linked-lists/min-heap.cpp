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
  and N is size of arr[]  */
typedef pair<int , Node*> pairs ;
Node * mergeKLists(Node *arr[], int N)
{
    priority_queue<pairs , vector<pairs> , greater<pairs>>minHeap ;
    for(int i = 0 ; i < N ; i++)
    {
        Node* head = arr[i] ;
        if(head)
            minHeap.push({head->data , head}) ;
    }
    Node* head = new Node(INT_MIN) ;
    Node* currNode = head ;
    while(!minHeap.empty())
    {
        auto details = minHeap.top() ;
        minHeap.pop() ;
        int data = details.first ;
        Node* address = details.second ;
        currNode->next = address ;
        currNode = currNode->next ;
        address = address->next ;
        if(address)
            minHeap.push({address->data , address}) ;
    }
    return head->next ;
}

