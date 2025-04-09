from pt4 import *
def solve():
    task("TimD1")
    N = get();
    matrix = []
    
    for i in range(N):
        row = []
        for j in range(N):
            row.append(get())  
        matrix.append(row)  
    
    result = []
    for d in range(2 * N - 1):
        if d < N:
            row = d
            col = 0
        else:
            row = N - 1
            col = d - N + 1
            
        while row >= 0 and col < N:
            put(matrix[row][col])
            row -= 1
            col += 1

start(solve)
