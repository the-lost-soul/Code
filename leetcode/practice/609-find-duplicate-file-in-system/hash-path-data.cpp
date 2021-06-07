class Solution {
public:
    vector<vector<string>> findDuplicate(vector<string>& paths) ;
    
} ;

vector<vector<string>> Solution :: findDuplicate(vector<string>& paths)
{
    unordered_map<string , vector<string>>hash ; 
    for(auto str : paths)
    {
        stringstream ss(str) ;
        string directory ;
        ss >> directory ;
        directory += '/' ;
        string files ;
        while(ss >> files)
        {
            string fileName = "" ;
            int i = 0 ;
            while(files[i] != '(')
            {
                fileName += files[i] ;
                i++ ;
            }
            string data = files.substr(i , (int)files.length()) ;
            hash[data].push_back(directory + fileName) ;
        }
        cout << endl ;
    }
    
    vector<vector<string>>ans ;
    for(auto itr : hash)
    {
        vector<string>res = itr.second ;
        if(res.size() > 1)
            ans.push_back(res) ;
    }
    return ans ;
}
