class Solution {
public:
    const int mod = 1e9 + 7 ;
    int findPaths(int m, int n, int N, int i, int j) ;
};

int Solution :: findPaths(int m , int n , int N , int i , int j)
{
    if(i < 0 or j < 0 or i >= m or j >= n)
        return 1 ;
    
    if(N == 0)
        return 0 ;
    int left = findPaths(m , n , N - 1 , i , j - 1) ;
    int right = findPaths(m , n , N - 1 , i , j + 1) ;
    int down = findPaths(m , n , N - 1 , i + 1 , j) ;
    int up = findPaths(m , n , N - 1 , i - 1 , j) ;
    return (left%mod + right%mod + up%mod + down%mod)%mod ;
}
