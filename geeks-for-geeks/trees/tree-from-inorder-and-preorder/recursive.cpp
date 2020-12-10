/*
Efficient Approach : 
We can optimize the above solution using hashing (unordered_map in C++ or HashMap in Java). We store indexes of inorder traversal in a hash table. So that search can be done O(1) time.
*/

/* MY APPROACH */

/* search the parent element in inorder array
 * and return the index where the element has 
 * been found 
 */
int search(int in[], int inStart, int inEnd, int data)
{
    for(int i=inStart; i<=inEnd; i++)
    {
        if(in[i]==data)return i;
    }
}

Node *buildTreeUtil(int in[], int pre[], int inStart, int inEnd, int *preIndex)
{
    
    // If at any instance inStart becomes greater
    // than zeo then return NULL
    if(inStart>inEnd)return NULL;
    
    
    // if we reach here then allocate memory for
    // sub tree parent
    Node *root=new Node;
    
    
    // preIndex denotes root of the subtree
    // so put that in root->data and increment
    // the preIndex variable to point to next parent
    // in preorder array
    root->data=pre[(*preIndex)++];
    root->left=NULL;
    root->right=NULL;
    
    
    if(inStart==inEnd)return root;
    // debugging
    //printf("%d\n",root->data);
    
    // Tells the position in inorder array
    // where the element i.e parent of sub-
    // tree is found
    int foundAtIndex=search(in, inStart, inEnd, root->data);
    
    // debugging
    // cout<<"found-->"<<foundAtIndex<<endl;
    
    
    // Make left subtree with help of index of inorder array
    root->left=buildTreeUtil(in, pre, inStart, foundAtIndex-1, preIndex);
    
    // Make right subtree with help of index of inorder array
    root->right=buildTreeUtil(in, pre, foundAtIndex+1, inEnd, preIndex);
    
    return root;
    
}
Node* buildTree(int in[],int pre[], int inStart, int inEnd)
{
    // Tells the index of parent of each subtree
    // at preorder array
    int preIndex=0;
    
    // utility function which returns root
    // of the constructed tree
    return buildTreeUtil(in, pre, inStart, inEnd, &preIndex);
}

