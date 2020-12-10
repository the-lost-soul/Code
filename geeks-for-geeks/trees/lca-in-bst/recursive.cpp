Node *findLCA(Node *root, int data, int temp)
{
    // BASE CASE
    if(root==NULL)return NULL;
    
    // If both n1 and n2 are greater than 
    // root then LCA lies in right sub-tree
    if(data>root->data && temp>root->data)
    return findLCA(root->right, data, temp);
    
    // If both n1 and n2 are less than 
    // root then LCA lies in left sub-tree
    else if(data<root->data && temp<root->data)
    return findLCA(root->left, data, temp);
    
    return root;
    
}
Node* LCA(Node *root, int n1, int n2)
{
   // Can be solved withhout using max and min
   int data=n1>n2?n1:n2;
   int temp=n1>n2?n2:n1;
   
   return findLCA(root,data,temp);
   
   
   
   
   
}

