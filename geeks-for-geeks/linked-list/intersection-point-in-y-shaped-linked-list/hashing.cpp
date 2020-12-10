#include<unordered_set>
int intersectPoint(Node* head1, Node* head2)
{
    // Your Code Here
    unordered_set<Node *>NodesAddress;
    while(head1!=NULL)
    {
        if(NodesAddress.find(head1)==NodesAddress.end())
        {
            NodesAddress.insert(head1);
            head1=head1->next;
        }
    }
    while(head2!=NULL)
    {
        if(NodesAddress.find(head2)==NodesAddress.end())
        {
            NodesAddress.insert(head2);
            head2=head2->next;
        }
        else
        {
            return head2->data;
        }
    }
    return -1;
}
/*
ANOTHER APPROACH IS TO TRAVERSE BOTH LIST ONE BY ONE AND GET LENGTH OF NODES IN EACH LIST,THEN,
IF(C1>C2)
{
D=C1-C2;
}
ELSE D=C2-C1
THEN CALL A FUNCTION GetIntersectionPoint
After calling this function first traverse the larger list d-1 times so that both list becomes equal in length and then a call a while(current1!=NULL&&current2!=NULL)
if(current1==current2)
Return current1->data
Else
current1=current1->next;
current2=current2->next;
*/
