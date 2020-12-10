/* ONE MORE SOLUTION IS TO USE LEVEL ORDER TRAVERSAL*/
* Utility function which returns true if both trees are identical else false */
bool isIdenticalUtil(Node *root1,Node *root2)
{
    // If both subtrees have root as NULL
    // i.e both are identical
    if(root1==NULL && root2==NULL) return 1;
    
    // If root of any one subtree becomes NULL
    // before other subtree then that means 
    // they are not identical
    if((root1==NULL && root2!=NULL)|| (root1!=NULL && root2==NULL)) return 0;
    
    // If root of subtree of both tree are 
    // not equal then they are not identical
    if(root1->data!=root2->data) return 0;
    
    /* Since,both trees have root data of same  
       value so we recursively call for left and 
       right subtrees of both trees*/
    
    return(isIdenticalUtil(root1->left,root2->left)&
            isIdenticalUtil(root1->right,root2->right));
}
/* Should return true if trees with roots as r1 and 
   r2 are identical */
bool isIdentical(Node *r1, Node *r2)
{
    // Your Code here
    /*utility function which returns bool value*/
    return(isIdenticalUtil(r1,r2));
    
}

