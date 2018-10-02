"""
N-Queen problem
Time Complexiy is exponential (it is based on the size of the table)
Space Complexiy - O(n)
"""

class N_Queen(object):

    def possibility(self,row,column,q_row,q_column):
        left_diagonal = q_row + q_column
        right_diagonal = q_row - q_column

        if q_row == row:
            return False
        elif q_column == column:
            return False
        elif row + column == left_diagonal:
            return False
        elif row - column == right_diagonal:
            return False
        else:
            return True


    def queen(self,n,row,previous_queen,result):
        if row == n:
            print result
            return True

        # Iterating the columns
        for j in range(n):
            valid = True
            for q in range(len(previous_queen)):
                if(not(self.possibility(row,j,previous_queen[q][0],previous_queen[q][1]))):
                    valid = False
                    break

            if(valid):
                previous_queen.append([row,j])
                result[row][j] = 'Queen'
                if(self.queen(n,row+1,previous_queen,result)):
                    return True
                else:
                    previous_queen.remove([row,j])
                    result[row][j] = 0

        return False


    def solveNQueens(self, n):

        result = []
        for i in range(n):
            result.append([])
            for j in range(n):
                # Void is zero - 0 
                result[i].append(0)
        previous_queen = []
        self.queen(n,0,previous_queen,result)


obj = N_Queen()
obj.solveNQueens(4)
