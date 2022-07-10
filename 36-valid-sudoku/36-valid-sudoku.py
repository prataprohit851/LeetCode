class Solution(object):
    def isValidSudoku(self, board):
        """
        :type board: List[List[str]]
        :rtype: bool
        """
        row = [[0]*9 for i in range(9)]
        column = [[0]*9 for i in range(9)]
        box = [[0]*9 for i in range(9)]
        for i in range(9):
            for j in range(9):
                if board[i][j] != '.':
                    
                    row[i][int(board[i][j])-1] += 1
                    column[j][int(board[i][j])-1] += 1
                    box[(i/3)*3 + j/3][int(board[i][j])-1] += 1
                    
                    if(row[i][int(board[i][j])-1] > 1 or column[j][int(board[i][j])-1] > 1 or box[(i/3)*3 + j/3][int(board[i][j])-1] > 1): return False

        return True