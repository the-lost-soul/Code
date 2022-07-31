/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    vector<int> nextLargerNodes(ListNode* head) ;
    void helper(ListNode * head , vector<int>&answer , stack<int>&currentMax) ;
};

/* Similar to Next Greater Element */
vector<int> Solution :: nextLargerNodes(ListNode* head)
{
    // Stores all the pre processed element which are greater than the pre processed nodes.
    stack<int>currentMax ;
    
    vector<int>answer ;
    
    if(head == nullptr) return answer ;
    
    helper(head , answer , currentMax) ;
    
    
    reverse(answer.begin() , answer.end()) ;
    
    return answer ;
}

void Solution :: helper(ListNode * head , vector<int>&answer , stack<int>&currentMax)
{
    // Recursion call .
    if(head->next != nullptr)helper(head->next , answer , currentMax) ;
    
    
    // since it is last element , so there are no greater element on it's right
    // hence push 0 and push the nodes value to stack .
    if(head->next == nullptr)
    {
        answer.push_back(0) ;
        currentMax.push(head->val) ;
    }
    else
    {
        // If the current node is not last node then find the first greater element present in stack
        // and pop rest .
        while((currentMax.top() <= head->val))
        {
            currentMax.pop() ;
            if(currentMax.empty())break ;
        }
    
        // If stack becomes empty then this means there are no elements at right which are
        // greter than current node's value .
        if(currentMax.empty())
        {
            answer.push_back(0) ;
            currentMax.push(head->val) ;
        }
        // If stack is not empty then push the top of stack to the answer vector and push the
        // current node's val to stack .
        else
        {
            answer.push_back(currentMax.top()) ;
            currentMax.push(head->val) ;
        }
    }
    
}

