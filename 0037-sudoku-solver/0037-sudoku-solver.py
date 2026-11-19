class Solution(object):
    def solveSudoku(self, board):
        """
        :type board: List[List[str]]
        :rtype: None Do not return anything, modify board in-place instead.
        """
        rows = [0] * 9
        cols = [0] * 9
        boxes = [0] * 9
        empty_cells = []

        for r in range(9):
            for c in range(9):
                if board[r][c] != '.':
                    val = int(board[r][c])
                    mask = 1 << val
                    rows[r] |= mask
                    cols[c] |= mask
                    boxes[(r // 3) * 3 + (c // 3)] |= mask
                else:
                    empty_cells.append((r, c))

        def backtrack(idx):
            if idx == len(empty_cells):
                return True
            
            r, c = empty_cells[idx]
            b = (r // 3) * 3 + (c // 3)
            
            used = rows[r] | cols[c] | boxes[b]
            
            for val in range(1, 10):
                mask = 1 << val
                if not (used & mask):
                    board[r][c] = str(val)
                    rows[r] |= mask
                    cols[c] |= mask
                    boxes[b] |= mask
                    
                    if backtrack(idx + 1):
                        return True
                    
                    rows[r] &= ~mask
                    cols[c] &= ~mask
                    boxes[b] &= ~mask
                    board[r][c] = '.'
            return False

        backtrack(0)