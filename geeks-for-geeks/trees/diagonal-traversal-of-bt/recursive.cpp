void printAnswer(multimap<int,int>myMap)
{
    for (auto itr = myMap.begin(); itr != myMap.end(); itr++)
    {
        cout<<itr->second<<" ";
    }
}
void findDiagonal(Node *root, multimap<int,int>&myMap, int position)
{
    // If tree is empty then do nothing.
    if(root==NULL)return ;
    
    // Push every node to map which is at a 
    // same distance from it's parent node.
    myMap.insert(make_pair(position,root->data));
    
    // Traverse the left sub-tree and increase
    // the distance by 1 as the digonal line is changing.
    if(root->left!=NULL)findDiagonal(root->left,myMap,position+1);
    
    // Traverse the right sub-tree but don't
    // increase it's distance as it is on same
    // diagonal line.
    if(root->right!=NULL)findDiagonal(root->right,myMap,position);
    
}
void diagonalPrint(Node *root)
{
    // If tree is empty then no need to traverse
    if(root==NULL)return ;
    
    // Store the value of root in vector for each 
    // value of position
    multimap<int,int>myMap;
    
    //diagonal distance of a node from it's parent node.
    int position=0;

    
    // Utility function which maps each node to it's
    // correct index of map.
    findDiagonal(root,myMap,position);
    
    // Utility function to print answer
    printAnswer(myMap);
}
