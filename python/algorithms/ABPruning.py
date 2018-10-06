import numpy as np
import sys
from copy import copy

rows = 3
cols = 3

board = np.zeros((rows,cols))

inf = float("inf")
neg_inf = float("-inf")

def printBoard():
    for i in range(rows):
        for j in range(cols):
            if board[i, j] == 0:
                sys.stdout.write(' _ ')
            elif board[i, j] == 1:
                sys.stdout.write(' X ')
            else:
                sys.stdout.write(' O ')
        print ''

# The heuristic function which will be evaluating board's position for each of the winning POS
heuristicTable = np.zeros((rows+1, cols+1))
numberOfWinningPositions = rows + cols + 2

for index in range(rows+1):
    heuristicTable[index, 0] = 10**index
    heuristicTable[0, index] =-10**index

winningArray = np.array([[0, 1, 2], [3, 4, 5], [6, 7, 8], [0, 3, 6], [1, 4, 7], [2, 5, 8], [0, 4, 8], [2, 4, 6]])


def utilityOfState(state):
    stateCopy = copy(state.ravel())
    heuristic = 0

    for i in range(numberOfWinningPositions):
        maxp = 0
        minp = 0
        for j in range(rows):
            if stateCopy[winningArray[i,j]] == 2:
                maxp += 1
            elif stateCopy[winningArray[i,j]] == 1:
                minp += 1
        heuristic += heuristicTable[maxp][minp]

    return heuristic

def minimax(state,alpha,beta,maximizing,depth,maxp,minp):

    if depth==0:
        return utilityOfState(state),state

    rowsLeft,columnsLeft=np.where(state==0)
    returnState=copy(state)
    if rowsLeft.shape[0]==0:
        return utilityOfState(state),returnState

    if maximizing==True:
        utility=neg_inf
        for i in range(0,rowsLeft.shape[0]):
            nextState=copy(state)
            nextState[rowsLeft[i],columnsLeft[i]]=maxp
            #print 'in max currently the Nextstate is ',nextState,'\n\n'
            Nutility,Nstate=minimax(nextState,alpha,beta,False,depth-1,maxp,minp)
            if Nutility > utility:
                utility=Nutility
                returnState=copy(nextState)
            if utility>alpha:
                alpha=utility
            if alpha >=beta :
                #print 'pruned'
                break;

        #print 'for max the best move is with utility ',utility,' n state ',returnState
        return utility,returnState

    else:
        utility=inf
        for i in range(0,rowsLeft.shape[0]):
            nextState=copy(state)
            nextState[rowsLeft[i],columnsLeft[i]]=minp
            #print 'in min currently the Nextstate is ',nextState,'\n\n'
            Nutility,Nstate=minimax(nextState,alpha,beta,True,depth-1,maxp,minp)
            if Nutility < utility:
                utility=Nutility
                returnState=copy(nextState)
            if utility< beta:
                beta=utility
            if alpha >=beta :
                #print 'pruned'
                break;
        return utility,returnState

def checkGameOver(state):
    stateCopy=copy(state)
    value=utilityOfState(stateCopy)
    if value >=1000:
        return 1
    return -1


def main():
    num=input('enter player num (1st or 2nd) ')
    value=0
    global board
    for turn in range(0,rows*cols):
        if (turn+num)%2==1: #make the player go first, and make the user player as 'X'
            r,c=[int(x) for x in raw_input('Enter your move ').split(' ')]

            board[r-1,c-1]=1
            printBoard()
            value=checkGameOver(board)
            if value==1:
                print 'U win.Game Over'
                sys.exit()
            print '\n'
        else: #its the computer's turn make the PC always put a circle'
            #right now we know the state if the board was filled by the other player 
            state=copy(board)
            value,nextState=minimax(state,neg_inf,inf,True,2,2,1)
            board=copy(nextState)
            printBoard()
            print '\n'
            value=checkGameOver(board)
            if value==1:
                print 'PC wins.Game Over'
                sys.exit()

    print 'Its a draw'

if __name__ == "__main__":
    main()