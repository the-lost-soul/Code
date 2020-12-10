void printLeftTree(Node *root)
{
    if(root!=NULL)
    {
        // If visited node is not leaf node.
        if(root->left!=NULL || root->right!=NULL)
        cout<<root->data<<" ";
        if(root->left!=NULL)
        printLeftTree(root->left);
        else if(root->right!=NULL)
        printLeftTree(root->right);
        
    }
}

/* Traverse the tree for each leaf node and visit from
left to right order */
void printLeaf(Node *root)
{
    // Traverse the left sub-tree.
    if(root->left!=NULL)printLeaf(root->left);
    
    // Print the leaf node from left to right.
    if(root->left==NULL && root->right==NULL)cout<<root->data<<" ";
    // Traverse the right sub-tree.
    if(root->right!=NULL)printLeaf(root->right);
}

void printRightTree(Node *root)
{
    // Traverse right sub tree and visit it
    if(root->right!=NULL)printRightTree(root->right);
    
    // If right child is not present then visit 
    // left child if present
    else if(root->left!=NULL)printRightTree(root->left);
    
    // If the node is not a leaf node then print it.
    if(root->left!=NULL || root->right!=NULL)cout<<root->data<<" ";
}

void printBoundary(Node *root)
{
    // Print root
    cout<<root->data<<" ";
    
    // Print left tree nodes
    if(root->left!=NULL)
    printLeftTree(root->left);
    
    //Print leaf nodes of left sub tree
    if(root->left!=NULL)
    printLeaf(root->left);
    
    if(root->right!=NULL)
    printLeaf(root->right);
    
    // Print right sub tree nodes
    if(root->right!=NULL)
    printRightTree(root->right);
    
}

