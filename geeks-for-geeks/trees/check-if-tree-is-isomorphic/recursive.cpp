bool isIsomorphic(Node *root1 , Node *root2)
{
    if(!root1 and !root2)return true ;
    if((!root1 and root2) or (root1 and !root2))return false ;
    if(root1->data != root2->data)return false ;
    else return isIsomorphic(root1->left , root2->left) 
        or isIsomorphic(root1->right , root2->right)
        or isIsomorphic(root1->left , root2->right) 
        or isIsomorphic(root1->right , root2->left);
}
