
/* Do any tree traversal and decrement count of level
 * in each recursive calls till the time we reach level 0 , 
 * then just print the roots data of that level .
 */
void printKdistance(Node *root, int k)
{
    if(k == 0)cout<<root->data <<" " ;
    else
    {
        if(root->left)printKdistance(root->left , k - 1) ;
        if(root->right)printKdistance(root->right , k - 1) ;
    }
}
