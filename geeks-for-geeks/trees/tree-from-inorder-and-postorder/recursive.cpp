// Function should construct tree and return
// root of it.  in[] stores inorder traversal
// post[] stores postorder traversal.  n is
// size of these arrays

Node *newNodes(int data)
{
    Node *root=new Node;
    root->data=data;
    root->right=NULL;
    root->left=NULL;
    return root;
}
Node *buildTreeUtil(int in[], int post[], int inStart, int inEnd, unordered_map<int,int>&inorder, int *postIndex)
{
    
    if(inStart>inEnd)return NULL;
    
    // Allocate memory for root of sub-tree
    // and decrement the postIndex to point to
    // the next element of postorder array
    Node *root=newNodes(post[(*postIndex)--]);
    
    // Stores the index of the root->data
    // and this variable divides the inorder
    // array in to two halves
    int foundAtIndex=inorder[root->data];
    
    // If at any any point this condition gets satisfied
    // then we have only one element left in inorder array
    // then return root
    if(inStart==inEnd)return root;
    
    // make right subtree
    root->right=buildTreeUtil(in ,post, foundAtIndex+1, inEnd, inorder, postIndex);
    
    // make left subtree 
    root->left=buildTreeUtil(in ,post, inStart, foundAtIndex-1, inorder, postIndex);
    
    return root;
    
}

// Function should construct tree and return
// root of it.  in[] stores inorder traversal
// post[] stores postorder traversal.  n is
// size of these arrays
Node *buildTree(int in[], int post[], int n)
{
    int postIndex=n-1;
    
    // use hashing to insert index of
    // every element of inorder array 
    // to the hash table.
    // The reason we are doing is this
    // to reduce the time complexity of 
    // searching each parent of sub-tree
    // from O(n) to O(1)
    unordered_map<int,int>inorder;
    for(int i=0; i<n; i++)
    {
        inorder[in[i]]=i;
    }
    return buildTreeUtil(in, post, 0, n-1, inorder, &postIndex);
    
}

