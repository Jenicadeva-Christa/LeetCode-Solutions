from typing import List
class Solution:
    def solveNQueens(self, n: int) -> List[List[str]]:
        results = []
        cols = set()
        diagonals = set()     
        anti_diagonals = set() 
        queens = [-1] * n
        def backtrack(row: int):
            if row == n:
                board = []
                for r in range(n):
                    row_str = ['.'] * n
                    row_str[queens[r]] = 'Q'
                    board.append(''.join(row_str))
                results.append(board)
                return
            for col in range(n):
                diag = row - col
                anti_diag = row + col
                if col in cols or diag in diagonals or anti_diag in anti_diagonals:
                    continue
                cols.add(col)
                diagonals.add(diag)
                anti_diagonals.add(anti_diag)
                queens[row] = col
                backtrack(row + 1)
                cols.remove(col)
                diagonals.remove(diag)
                anti_diagonals.remove(anti_diag)
            queens[row] = -1
        backtrack(0)
        return results