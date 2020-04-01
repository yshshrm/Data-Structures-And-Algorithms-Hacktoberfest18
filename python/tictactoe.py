from tkinter import *
from tkinter import messagebox


def Start():
	global start
	global name
	if(name!=''):
		messagebox.showinfo("TicTacToe","Hi "+name+"! Lets play.")
	else:
		messagebox.showinfo("Error","Enter your name")
	start = 1

def PossWin(move, board):
	for i in move:
		for j in move:
			n = move[i]+move[j]
			if(n < 9 and n > 0 and move[i]!=move[j]):
				next_move = 15 - n
				if(board[next_move] != 'X' or board[next_move] != 'O'):
					return next_move
	return 0
			
def checkWin(player, new_move):
	for i in player:
		for j in player:
			n = i + j
			if((i!=new_move) and (j!=new_move) and (n+new_move == 15) and (i!=j)):
				return 1
	return 0

def nextMove(new_move, btn):

	global empty
	global count
	global c_win
	global name

	if start == 0:
		messagebox.showinfo("Error","Press start button")
		return


	if new_move not in empty:
		messagebox.showinfo("Error","Wrong move! Try another move")
		return
				
	count += 1
	H.append(new_move)
	empty.remove(new_move)
	board[board.index(new_move)] = 'X'
	btn["text"] = "X"

	if count > 5:
		return

	########################################### computers move #####################################
	if count == 1:
		if 5 in board:
			Go(5, button5)
		else:
			Go(4, button3)  

	else:       
		flag = 0
		flag2 = 0
		if(checkWin(H, new_move) == 1):
			messagebox.showinfo("Winner","Congratulations",name,"! You win")
			exit()

		if(empty == []):
			messagebox.showinfo("Draw","Its a draw! Try again.")
			exit()
			

		for i in empty:
			if(checkWin(C, i) == 1):
				Go(i,Go_to(i))
				messagebox.showinfo("Loser","Computer wins. Try again!")
				exit()

		for i in empty:
			if(checkWin(H,i) == 1):
				Go(i,Go_to(i))
				flag = 1
				break

		if(flag == 0):
			for i in empty:
				if(i == 8 or i == 4 or i == 6 or i == 2):
					Go(i,Go_to(i))
					flag2 = 1
					break
			
			if(flag2 == 0):
				Go(empty[0],Go_to(empty[0]))


def Go_to(i):
	switcher = {

	8:  button1,
	3:  button2,
	4:  button3,
	1:  button4,
	5:  button5,
	9:  button6,
	6:  button7,
	7:  button8,
	2:  button9

	}
	return switcher.get(i)

def Go(new_move, btn):
	global empty
	empty.remove(new_move)

	board[board.index(new_move)] = 'O'
	C.append(new_move)
	btn["text"] = 'O'

start = 0
count = 0
c_win = 0
empty = [8, 3, 4, 1, 5, 9, 6, 7, 2]
board = [8, 3, 4, 1, 5, 9, 6, 7, 2]
C = []
H = []

root = Tk()

L1 = Label(root, text="Enter your name")
L1.pack( side = TOP)
v = StringVar()
E1 = Entry(root,textvariable = v, bd =5)
E1.pack(side = TOP) 
v.set("Anonymous")
name = v.get()

button = Button(root, text = 'START', fg ='black', command = Start)
button.pack(side = TOP)

frame = Frame(root)
frame.pack()
middleframe = Frame(root)
middleframe.pack()
bottomframe = Frame(root)
bottomframe.pack( side = BOTTOM )

button1 = Button(frame, text = '', fg ='black', height = 4, width = 4)
button1['command'] = lambda move = 8 : nextMove(move, button1)
button1.pack( side = LEFT)

button2 = Button(frame, text = '', fg ='black', height = 4, width = 4)
button2['command'] = lambda move = 3 : nextMove(move, button2)
button2.pack( side = LEFT)

button3 = Button(frame, text = '', fg ='black', height = 4, width = 4)
button3['command'] = lambda move = 4 : nextMove(move, button3)
button3.pack( side = LEFT)

button4 = Button(middleframe, text = '', fg ='black', height = 4, width = 4)
button4['command'] = lambda move = 1 : nextMove(move, button4)
button4.pack( side = LEFT)

button5 = Button(middleframe, text = '', fg ='black', height = 4, width = 4)
button5['command'] = lambda move = 5 : nextMove(move, button5)
button5.pack( side = LEFT)

button6 = Button(middleframe, text = '', fg ='black', height = 4, width = 4)
button6['command'] = lambda move = 9 : nextMove(move, button6)
button6.pack( side = LEFT)

button7 = Button(bottomframe, text = '', fg ='black', height = 4, width = 4)
button7['command'] = lambda move = 6 : nextMove(move, button7)
button7.pack( side = LEFT)

button8 = Button(bottomframe, text = '', fg ='black', height = 4, width = 4)
button8['command'] = lambda move = 7 : nextMove(move, button8)
button8.pack( side = LEFT)

button9 = Button(bottomframe, text = '', fg ='black', height = 4, width = 4)
button9['command'] = lambda move = 2 : nextMove(move, button9)
button9.pack( side = LEFT)

root.mainloop()

