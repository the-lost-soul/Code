class ThroneInheritance
{
    unordered_map<string , vector<string>>parent_child ;
    unordered_map<string , int>dead_alive ;
    string king ;
public:
    ThroneInheritance(string kingName)
    {
        this->king = kingName ;
        parent_child["null"].push_back(kingName) ;
        dead_alive[kingName] = 1 ;
    }
    
    void birth(string parentName, string childName)
    {
        parent_child[parentName].push_back(childName) ;
        dead_alive[childName] = 1 ;
    }
    
    void death(string name)
    {
        dead_alive[name] = 0 ;
    }
    void inorder(string king , vector<string>&order)
    {
        if(dead_alive[king] == 1)order.push_back(king) ;
        vector<string>childrens = parent_child.find(king) != parent_child.end() ? parent_child[king] : vector<string>{} ;
        for(auto child : childrens)
        {
            inorder(child , order) ;
        }
    }
    vector<string> getInheritanceOrder()
    {
        vector<string>order ;
        inorder(king , order) ;
        return order ;
    }
    
};

/**
 * Your ThroneInheritance object will be instantiated and called as such:
 * ThroneInheritance* obj = new ThroneInheritance(kingName);
 * obj->birth(parentName,childName);
 * obj->death(name);
 * vector<string> param_3 = obj->getInheritanceOrder();
 */
