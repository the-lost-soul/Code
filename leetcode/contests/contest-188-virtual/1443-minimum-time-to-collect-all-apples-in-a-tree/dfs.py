class Solution:
    def minTime(self, n: int, edges: List[List[int]], hasApple: List[bool]) -> int:
        nodes = defaultdict(list)
        for ele in edges :
            nodes[ele[0]].append(ele[1])
            nodes[ele[1]].append(ele[0])
        visited = [False]*n
        
        
        def helper(root , currentCost) :
            if(visited[root]) :
                return 0
            visited[root] = True
            childrenCost = 0
            for child in nodes[root] :
                childrenCost += helper(child , 2)
            if(childrenCost == 0 and hasApple[root] == False) :
                return 0
            return childrenCost + currentCost
    

        return helper(0 , 0)
