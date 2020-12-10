class Solution {
    const int mod = 1e9 + 7 ;
public:
    int maxArea(int h, int w, vector<int>& horizontalCuts, vector<int>& verticalCuts) ;
};

int Solution :: maxArea(int h, int w, vector<int>& hCuts, vector<int>& vCuts)
{
    sort(begin(hCuts) , end(hCuts)) ;
    sort(begin(vCuts) , end(vCuts)) ;
    
    set<int>heightDiff ;
    heightDiff.insert(hCuts[0]) ;
    for(int i = 1 ; i < hCuts.size() ; i++)
    {
        heightDiff.insert(hCuts[i] - hCuts[i - 1]) ;
    }
    heightDiff.insert(h - hCuts[hCuts.size() - 1]) ;
    
    set<int> widthDiff ;
    widthDiff.insert(vCuts[0]) ;
    for(int i = 1 ; i < vCuts.size() ; i++)
    {
        widthDiff.insert(vCuts[i] - vCuts[i - 1]) ;
    }
    widthDiff.insert(w - vCuts[vCuts.size() - 1]) ;
    int hStrip = *(--heightDiff.end()) ;
    int wStrip = *(--widthDiff.end()) ;
    return (int)(((long)hStrip*wStrip)%mod) ;
}
