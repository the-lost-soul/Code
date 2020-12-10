class Solution {
public:
    vector<vector<string>> displayTable(vector<vector<string>>& orders) ;
};

vector<vector<string>> Solution :: displayTable(vector<vector<string>>& orders)
{
    set<int>tableNum ;
    set<string>food ;
    for(auto details : orders)
    {
        tableNum.insert(stoi(details[1])) ;
        food.insert(details[2]) ;
    }
    vector<string>menu ;
    menu.push_back("Table") ;
    for(auto name : food)
        menu.push_back(name) ;
    vector<vector<string>>ans(tableNum.size() + 1 , vector<string>(food.size() + 1 , "0")) ;
    ans[0] = menu ;
    int i = 1 ;
    for(auto num : tableNum)
    {
        ans[i][0] = to_string(num) ;
        i++ ;
    }
    
    unordered_map<string , int>foodAdd , tableAdd ;
    for(int i = 1 ; i < ans.size() ; i++)
    {
        tableAdd[ans[i][0]] = i ;
    }
    
    for(int i = 1 ; i < ans[0].size() ; i++)
    {
        foodAdd[ans[0][i]] = i ;
    }
    
    for(auto details : orders)
    {
        string food = details[2] , table = details[1] ;
        string y = ans[tableAdd[table]][foodAdd[food]] ;
        stringstream s(y) ;
        int x = 0 ;
        s >> x ;
        x++ ;
        ans[tableAdd[table]][foodAdd[food]] = to_string(x) ;
    }
    return ans ;
    
    
    
    
}
