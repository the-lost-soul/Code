class Solution {
public:
    TreeNode* bstFromPreorder(vector<int>& preorder) ;
};


TreeNode * Solution :: bstFromPreorder(vector<int>&preorder)
{
    
    stack <TreeNode *> s ;
    
    // The first element of preorder is root , so construct tree and push it to stack .
    TreeNode * root = new TreeNode(preorder[0]) ;
    s.push(root) ;
    

    TreeNode* temp ;
    
    // For every element do following -- 
    for(int i = 1 ; i < preorder.size() ; i++)
    {
        // it keeps record of the popped elemnt which is lesser than i'th element of preorder .
        temp = nullptr ;
        
        // Pop from stack while we are getting the top of stack less than the current element .
        while(!s.empty() && preorder[i] > s.top()->val)
        {
            temp = s.top() ;
            s.pop() ;
        }
        
        // If temp is null , then this means that the i'th element of preorder is less than the
        // elemnt present at top of stack , so make this i'th value as root of left sub-tree
        // having parent s.top() .
        if(!temp)
        {
            // Make a new node and initialise it's data equal to preorder[i] .
            s.top()->left = new TreeNode(preorder[i]) ;
            
            // Push the elemnt to stack .
            s.push(s.top()->left) ;
        }
        
        // if temp is not nullptr then this means that there were some elemnts in stack for which
        // i'th element was greater , so make i'th element the right child of last popped node .
        else
        {
            temp->right = new TreeNode(preorder[i]) ;
            
            // Push the newly constructed node to stack .
            s.push(temp->right) ;
        }
        
    }
    
    return root ;
}

