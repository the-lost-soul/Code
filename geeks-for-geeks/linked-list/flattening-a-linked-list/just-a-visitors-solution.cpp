
/* BHAIYYA’s CODE */
#include <iostream>
using namespace std;

/* Flattening a linked list */

struct Node
{
    int data;
    struct Node *next;
    struct Node *bottom;
};

/* Merges the 2 sorted vertical linked list and returns new list in vertical format*/
Node *mergeVertical(Node *headFirst, Node*headSecond)
{
    // If first list is empty, the 2nd list is the answer
    if(!headFirst) return headSecond;
    
    // If the second list is empty, the 1st list is the answer
    if(!headSecond) return headFirst;
    
    // What if both are empty? Already Handled
    
    /* So now assume each list contains at least one element */
    
    // Create the list for storing the results
    Node *sortedList;
    
    // Check if the first list goes first
    if(headFirst->data < headSecond->data)
    {
        sortedList = headFirst;
        
        // Recursively sort the remaining list and link it vertically
        sortedList->bottom = mergeVertical(headFirst->bottom, headSecond);
    }
    
    // If the 2nd list goes first
    else 
    {
        sortedList = headSecond;
        
        // Recursively sort the remaining list and link it
        sortedList->bottom = mergeVertical(headFirst, headSecond->bottom);
    }
    
    return sortedList;
}

/* Blocks all the  next pointers of the vertical list */
void blockNextPointers(Node *head)
{
    // List is empty, no need to block
    if(!head) return;
    
    // keep on going to the bottom and delete the next pointers
    while(head!=nullptr)
    {
        head->next = nullptr;
        head = head->bottom;
    }
}

/* Flattens several sorted vertical lists into a single sorted list (vertical) */
Node *flattenList(Node *head)
{
    // If the list is empty, return it as it is
    if(!head) return nullptr;
    
    // If it contains only one vertical list, return it as it is in the correct format
    if(head->next == nullptr) return head;
    
    /* So now assume there 2 or more vertical list */
    
    // Create the list to store the results 
    Node *result;
    
    // Flatten all other linked list(except first) into a single one
    Node *subResult = flattenList(head->next);
    
    /* So now subResult contains a single vertical list containing all the elements
       to the right of the first element, but in a sorted an vertical manner */
       
    // So now just merge the 2 vertical lists
    result = mergeVertical(head, subResult);
    
    // All that is left is to block all the next pointers
    blockNextPointers(result);
    
    return result;
}

int main() 
{
    return 0; 
} 
