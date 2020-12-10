int height(Node* node)
{
   // If subtree is empty
   if(node==NULL)return 0;

   // Compute the height of left subtree
   int leftHeight=height(node->left);
   
   // Compute the height of right subtree
   int rightHeight=height(node->right);

   // The max of two plus 1(for current node) will be height
   return 1+max(leftHeight,rightHeight);
}

