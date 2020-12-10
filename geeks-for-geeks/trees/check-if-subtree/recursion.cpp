/*you are required to 
complete this function */
bool isSubtree(Node * tree , Node * subTree)
{
    if(!tree and !subTree)return true ;
    if((!tree and subTree) or (tree and !subTree))return false ;
    // if(tree and !subTree)return false ;
    if(tree->data == subTree->data and 
       isSubtree(tree->left , subTree->left)
       and isSubtree(tree->right , subTree->right))
       return true ;
    else return isSubtree(tree->left , subTree) or isSubtree(tree->right , subTree) ;
}
