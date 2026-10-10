from collections import deque
class Solution:
    def orangesRotting(self, grid: List[List[int]]) -> int:
        
        n=len(grid)
        m=len(grid[0])
        fresh=0
        rotten=deque([])
        mins=0

        neigh =[(0,1),(0,-1),(1,0),(-1,0)]

        for row in range(n):
            for col in range(m):
                if grid[row][col] ==2:
                    rotten.append((row,col))
                elif grid[row][col] ==1:
                    fresh+=1
        if fresh==0:
            return 0
        while rotten:

            for i in range(len(rotten)):

                node = rotten.popleft()

                for ngh in neigh:
                    x = node[0]+ngh[0]
                    y = node[1]+ngh[1]
                    if 0<=x<n and 0<=y<m and grid[x][y]==1:
                        grid[x][y]=2 
                        
                        rotten.append((x,y))
                        fresh-=1
            mins+=1
        
        if fresh==0:
            return mins-1
        else:
            return -1

        

        

