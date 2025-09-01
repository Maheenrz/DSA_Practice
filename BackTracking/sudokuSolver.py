
  
def sudokuSolver(board):
    
    for r in range(len(board)):
        for c in range(len(board)):
            if board[r][c] == '.':
                for num in range(1,10):
                    if(isValid(board, r, c , num)):
                        board[r][c] = str(num)
                        if sudokuSolver(board):
                            return True
                            
                board[r][c]='.'            
                return False
    return True            





def isValid(board, r, c, num):
        num = str(num)

        row_start = (r // 3) * 3
        col_start = (c // 3) * 3

        for i in range(9):
            # check row
            if board[r][i] == num:
                return False
            # check col
            if board[i][c] == num:
                return False
            # check 3x3 block
            if board[row_start + i // 3][col_start + i % 3] == num:
                return False

        return True                
    
  
  
        
board = [["5","3",".",".","7",".",".",".","."],
         ["6",".",".","1","9","5",".",".","."],
         [".","9","8",".",".",".",".","6","."],
         ["8",".",".",".","6",".",".",".","3"],
         ["4",".",".","8",".","3",".",".","1"],
         ["7",".",".",".","2",".",".",".","6"],
         [".","6",".",".",".",".","2","8","."],
         [".",".",".","4","1","9",".",".","5"],
         [".",".",".",".","8",".",".","7","9"]]
         
         
         
    
    
sudokuSolver(board)

for r in range(9):
        row = ""
        for c in range(9):
            row += board[r][c] + " "
            if c == 2 or c == 5:   # add vertical separators
                row += "| "
        print(row.strip())
        if r == 2 or r == 5:      # add horizontal separators
            print("------+-------+------")   
