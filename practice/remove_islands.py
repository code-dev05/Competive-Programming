matrix = [
    [1, 0, 0, 0, 0, 0],
    [0, 1, 0, 1, 1, 1],
    [0, 0, 1, 0, 1, 0],
    [1, 1, 0, 0, 1, 0],
    [1, 0, 1, 1, 0, 0],
    [1, 0, 0, 0, 0, 1]
]

def is_border(i, j, row, col):
    if i == 0 or i == row - 1 or j == 0 or j == col -1:
        return True
    return False

def is_valid(i, j, row, col):
    if i >= 0 and i < row and j >= 0 and j < col:
        return True
    return False

def dfs(i, j, matrix, connected, row, col):
    dx = [-1, 0, 1, 0]
    dy = [0, 1, 0, -1]
    connected[i][j] = 1
    for x in range(4):
        X = i + dx[x]
        Y = j + dy[x]
        if is_valid(X, Y, row, col) and matrix[X][Y] == 1 and connected[X][Y] == 0:
            connected = dfs(X, Y, matrix, connected, row, col)
    return connected

def print_matrix(matrix):
    row = len(matrix)
    col = len(matrix[0])
    for row in matrix:
        for col in row:
            print(col, end=' ')
        print()

def removeIslands(matrix):
    row = len(matrix)
    col = len(matrix[0])
    connected = [[0 for _ in range(col)] for _ in range(row)]
    for i, r in enumerate(matrix):
        for j, c in enumerate(r):
            if c == 1 and is_border(i, j, row, col):
                if connected[i][j] == 0:
                    connected = dfs(i, j, matrix, connected, row, col)
    
    for i, row in enumerate(matrix):
        for j, col in enumerate(row):
            if col == 1 and connected[i][j] == 0:
                matrix[i][j] = 0
        
    return matrix

if __name__ == '__main__':
    matrix = removeIslands(matrix)
    print_matrix(matrix)