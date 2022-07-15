class Solution
{
    boolean[][] visited ;
    int[][] grid ;

    public boolean isValidDir(int i , int j , int r , int c)
    {
        if(i >= 0 && i < r && j >= 0 && j < c)
            return true ;
        return false ;
    }

    public int dfs(int startRow , int startCol , int row , int col)
    {
        Stack<Pair<Integer , Integer>> stk = new Stack<>() ;
        Pair<Integer , Integer> pr = new Pair(startRow , startCol) ;
        stk.push(pr) ;
        int area = 0 ;
        while(!stk.empty())
        {
            pr = stk.peek() ;
            stk.pop() ;
            int r = pr.getKey() ;
            int c = pr.getValue() ;
            // To skip those cells which were already visited but
            // are still present in stack .
            // Eg -- [[1 , 1] , [1 , 1]] -- If we dont add this if
            // statement , then max area will be 5 instead of 4 .
            if(visited[r][c])
                continue ;
            visited[r][c] = true ;
            area++ ;
            if(isValidDir(r , c + 1 , row , col))
                if(grid[r][c + 1] == 1 && !visited[r][c + 1])
                    stk.push(new Pair(r , c + 1)) ;

            if(isValidDir(r , c - 1 , row , col))
                if(grid[r][c - 1] == 1 && !visited[r][c - 1])
                    stk.push(new Pair(r , c - 1)) ;

            if(isValidDir(r + 1 , c , row , col))
                if(grid[r + 1][c] == 1 && !visited[r + 1][c])
                    stk.push(new Pair(r + 1 , c)) ;

            if(isValidDir(r - 1 , c , row , col))
                if(grid[r - 1][c] == 1 && !visited[r - 1][c])
                    stk.push(new Pair(r - 1 , c)) ;
        }
        return area ;
    }
    public int maxAreaOfIsland(int[][] grid)
    {
        visited = new boolean[grid.length][grid[0].length] ;
        this.grid = grid ;
        int area = Integer.MIN_VALUE ;
        int row = grid.length , col = grid[0].length ;
        for(int i = 0 ; i < row ; i++)
            for(int j = 0 ; j < col ; j++)
                if(grid[i][j] == 1 && !visited[i][j])
                    area = Math.max(area , dfs(i , j , row , col)) ;
        return area == Integer.MIN_VALUE ? 0 : area ;
    }
}
