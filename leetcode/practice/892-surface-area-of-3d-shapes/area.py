class Solution:
    def surfaceArea(self, grid: List[List[int]]) -> int:
        area = 0
        row = col = len(grid)
        for r in range(row) :
            for c in range(col) :
                if grid[r][c] != 0 :
                    area += 2
                for currRow,currCol in ((r + 1 , c) , (r - 1 , c) , (r , c + 1) , (r , c - 1)) :
                    if(currRow >= 0 and currRow < row and currCol >= 0 and currCol < col) :
                        area += max(grid[r][c] - grid[currRow][currCol] , 0) 
                    else :
                        area += grid[r][c]
        
        return area
                    
