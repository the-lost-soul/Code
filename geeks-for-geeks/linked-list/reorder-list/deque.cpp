
/* The idea is to use deuqe because with this we can
 * access both first and last element of the list .
 * First get the last and first element from deque and 
 * do necessary link changing to get the desired result .
 * so basically after first link changing our new list
 * will look like -- a1->an->a2->a3.....
 * and then repeat the above steps till the deque size
 * is greater than 2 .
 */
void reorderList(Node* head) 
{
    deque <Node*>list ;
    Node* current = head ;
    while(current)
    {
        list.push_back(current) ;
        current = current->next ;
    }
    Node* first ;
    Node* last ;
    while(list.size() > 2)
    {
        first = list.front() ;
        last = list.back() ;
        last->next = first->next ;
        first->next = last ;
        list.pop_back() ;
        list.pop_front() ;
        if(!list.empty())
        {
            list.back()->next = nullptr ;
        }
    }
}
