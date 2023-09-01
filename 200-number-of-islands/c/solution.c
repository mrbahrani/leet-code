class Queue:
    def __init__(self):
        self.holder = []
        self.front = 0
        self.back = 0
    
    def put(self, x):
        self.holder.append(x)
    
    def get(self):
        if self.back < len(self.holder):
            self.back += 1
            return self.holder[self.back-1]
        else:
            return None
    def empty(self):
        return self.back == len(self.holder)
        
class Solution:
    def numIslands(self, grid: List[List[str]]) -> int:
        island_counter = 0
        for i in range(len(grid)):
            for j in range(len(grid[0])):
                if grid[i][j] == '1':
                    island_counter += 1
                    q = Queue()
                    q.put((i,j))
                    while not q.empty():
                        k, l = q.get()
                        if grid[k][l] == '-':
                            continue
                        grid[k][l] = '-'
                        if k > 0 and grid[k-1][l] == '1':
                            q.put((k-1, l))
                        if k < len(grid) - 1 and grid[k+1][l] == '1':
                            q.put((k+1, l))
                        if l > 0 and grid[k][l-1] == '1' :
                            q.put((k, l-1))
                        if l < len(grid[0]) - 1 and grid[k][l+1] == '1':
                            q.put((k, l+1))
        return island_counter
                    
