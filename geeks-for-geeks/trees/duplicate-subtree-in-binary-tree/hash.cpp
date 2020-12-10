string helper(Node* root , unordered_set<string>& subtrees)
{
    string s = "" ;
    if(!root)
    {
        return "$" ;
    }
    string l = helper(root->left , subtrees) ;
    if(l.compare(s) == 0)return s ;
    string r = helper(root->right , subtrees) ;
    if(r.compare(s) == 0)return s ;
    s += root->data + l + r ;
    if(s.length() > 3 and subtrees.find(s) != subtrees.end())
    {
        return "" ;
    }
    subtrees.insert(s) ;
    return s ;
}
/*This function returns true if the tree contains 
a duplicate subtree of size 2 or more else returns false*/
bool dupSub(Node *root)
{
    unordered_set<string>subtrees ;
    string s = helper(root , subtrees) ;
    return s.compare("") == 0 ? true : false ;
}
