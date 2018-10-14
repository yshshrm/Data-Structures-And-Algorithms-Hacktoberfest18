import os
import numpy as np
from grammar import rules
import argparse

#https://en.wikipedia.org/wiki/CYK_algorithm
#Usage: create a grammar.py file containing the rules
#S -> BC
#C -> SA
#A -> a
#B -> b
#Example: rules = {'S':['BC'], 'C':['SA','BA'], 'A':['a'], 'B':['b']} 
#Start with "python cykpars.py wordToParse"


def findRules(charItem):
	#Empty list to collect the rules found for the
	#Specific charItem
	rulesFound = []
	#Iterate trough rules from grammar.py
	for i,j in rules.items():
		for rule in j:
			#if a rule is found add it to the end of the list
			#Double check for multiple rules
			if rule == charItem:
				rulesFound.append(i)
	return rulesFound

def initArray(tWORD):
	length = len(tWORD)
	height = length
	tArray = np.zeros([height, length], list)
	return tArray

def parseFirst(tWORD, array):
	#possibleProductions = {}
	length = len(tWORD)
	height = length

	#parse first row of array
	#do this seperatly because if one terminalsymbol
	#cant be deducted the word cant be build
	for i in range(length):
		findC = tWORD[i]
		foundC = findRules(findC)
		array[0][i] = foundC
		if(len(foundC) == 0):
			print("Word cant be build with the given Grammar")

	return array


def getDiag(array, possibleProductions, currentLength, currentHeight, length, i, diagList):
	#Get Diagonal item from array
	#Diag length is the current height + the current length
	indexDiagLenght = currentHeight + currentLength
	indexDiagHeight = 0
	for diagLoopIndex in range(currentHeight):
		tempDiag = array[indexDiagHeight][indexDiagLenght]
		if(tempDiag == 0):
			tempDiag = ['EMPTY']
			diagList.append(tempDiag)
		else:
			diagList.append(tempDiag)
		#MOVE DIAG LEFT UP
		indexDiagLenght = indexDiagLenght - 1
		indexDiagHeight = indexDiagHeight + 1
	return diagList



def getDown(array, possibleProductions, currentHeight, currentLength):
	for indexHeight in range(currentHeight):
		tempSignal = array[indexHeight][currentLength]
		if(tempSignal == 0):
			#Add a empty element so both lists keep the same length
			possibleProductions.append(['EMPTY'])
		else:
			possibleProductions.append(tempSignal)
	#Reverse list because algorithm usually works the other way around
	possibleProductions.reverse()
	return possibleProductions


def checkCombinations(array, possibleProductions, diagList, currentLength, currentHeight):
	#clear rulesFound for the next field
	rulesFound = []
	#range doesnt matter because both lists have the same length
	for i in range(len(possibleProductions)):
		#Check for multiple characters in possibleProductions list
		for u in range(len(possibleProductions[i])):
			tempPos = possibleProductions[i][u]
			#Check for multiple characters in diagList
			for h in range(len(diagList[i])):
				tempDiag = diagList[i][h]
				#If one of the two characters is set as empty there cant be a production due to CNF
				if(tempPos == ['EMPTY']):
					dummy = 9
				elif(tempDiag == ['EMPTY']):
					dummy = 9
				else:
					searchC = ''.join(item for item in tempPos + tempDiag)
					for k, l in rules.items():
						for rule in l:
							if rule == searchC:
								rulesFound.append(k)

	if(len(rulesFound) == 0):
		#No rules found, dont make a entry
		return array
	else:
		#Rule found enter Rule in field
		array[currentHeight][currentLength] = rulesFound
		return array


def parse(tWORD, array, i):
	length = len(tWORD)
	currentHeight = i
	#The algorithm doesnt need to check every field in the array
	widthLength = length - i
	for currentLength in range(widthLength):
		possibleProductions = []
		diagList = []
		possibleProductions = getDown(array, possibleProductions, currentHeight, currentLength)
		diagList = getDiag(array, possibleProductions, currentLength, currentHeight, length, i, diagList)
		array = checkCombinations(array, possibleProductions, diagList, currentLength, currentHeight)

	return array

def main():
	parser = argparse.ArgumentParser(description="CYK Parser in Python")
	group = parser.add_mutually_exclusive_group()
	parser.add_argument("WORD", type=str, help="word to parse")
	args = parser.parse_args()
	tWORD = args.WORD

	array = initArray(tWORD)
	array = parseFirst(tWORD, array)
	height = len(tWORD) - 1
	for i in range(1, len(tWORD)):
		array = parse(tWORD, array, i)
	#print(array)

	checkWord = array[height][0]
	if(checkWord == 0):
		print("Word cant be built with the given Grammar")

	else:
		possible = False
		for h in range(len(checkWord)):
			if(checkWord[h] == 'S'):
				possible = True
		if(possible == True):
			print("Word can be built with the given Grammar")
			print(array)
		else:
			print("Word cant be built with the given Grammar")


if __name__ == "__main__":
main()