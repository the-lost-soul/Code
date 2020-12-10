
/* The idea here is to use in-ordre taversal of a BST
 * as it gives the BST in sorted form and store each 
 * nodes data in vector .
 */
void helper1(Node * root , vector<int> &vec)
{
    if(root == nullptr) return ;
    
    helper1(root->left , vec) ;
    vec.push_back(root->data) ;
    helper1(root->right , vec) ;
}

void helper2(Node * root , vector<int> &vec)
{
    if(root == nullptr) return ;
    
    helper2(root->left , vec) ;
    vec.push_back(root->data) ;
    helper2(root->right , vec) ;
    
}

void mergeHelper(vector<int> vec1 , vector<int> vec2)
{
    int index1 = 0 ;
    int index2 = 0 ;
    
    /* print the vector elements in increasing order until  
     * any one becomes empty or both becomes empty .
     */
    while(index1 < vec1.size() && index2 < vec2.size())
    {
        if(vec1[index1] >= vec2[index2])
        {
            cout << vec2[index2] <<" " ;
            index2 ++ ;
        }
        else
        {
            cout << vec1[index1] <<" " ;
            index1 ++ ;
        }
    }
    
    // Print the rest elements .
    if(index1 == vec1.size())
    {
        while(index2 < vec2.size())
        {
            cout << vec2[index2] <<" " ;
            index2 ++ ;
        }
    }
    else
    {
        while(index1 < vec1.size())
        {
            cout << vec1[index1] <<" " ;
            index1 ++ ;
        }
    }
}

void merge(Node *root1, Node *root2)
{
    
    vector<int>vec1 ;
    helper1(root1 , vec1) ;
    
    vector<int>vec2 ;
    helper2(root2 , vec2) ;
    
    mergeHelper(vec1 , vec2) ;
    
}
