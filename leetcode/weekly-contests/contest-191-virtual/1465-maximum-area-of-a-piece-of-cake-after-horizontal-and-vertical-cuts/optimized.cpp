class Solution {
    const int mod = 1e9 + 7 ;
public:
    int maxArea(int h, int w, vector<int>& horizontalCuts, vector<int>& verticalCuts) ;
};

int Solution :: maxArea(int h, int w, vector<int>& hCuts, vector<int>& vCuts)
{
    sort(begin(hCuts) , end(hCuts)) ;
    sort(begin(vCuts) , end(vCuts)) ;
    
    int hStrip = max(hCuts[0] , h - hCuts[hCuts.size() - 1]) ;
    for(int i = 1 ; i < hCuts.size() ; i++)
    {
        hStrip = max(hStrip , hCuts[i] - hCuts[i - 1]) ;
    }
    
    int wStrip = max(vCuts[0] , w - vCuts[vCuts.size() - 1]) ;
    for(int i = 1 ; i < vCuts.size() ; i++)
    {
        wStrip = max(wStrip , vCuts[i] - vCuts[i - 1]) ;
    }
    return (int)(((long)hStrip*wStrip)%mod) ;
}
