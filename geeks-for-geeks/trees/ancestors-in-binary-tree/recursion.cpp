bool printAncestors(struct Node *root, int target)
{
    if(!root)return false ;
    bool foundTarget ;
    if(root->data == target)return true ;
    foundTarget = printAncestors(root->left , target) ;
    if(!foundTarget)foundTarget = printAncestors(root->right , target) ;
    if(foundTarget)
    {
        cout << root->data << " " ;
    }
    return foundTarget ;
}
