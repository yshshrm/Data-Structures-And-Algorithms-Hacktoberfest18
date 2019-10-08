from makingFiles import makingFiles
from ibubble import ibubblesort
from bubble import bubblesort
from insertion import insertionsort
from selection import *
from merge import *
from quick import *

makingFiles()

comparisonFileBubble = open("BubbleComparison.txt", 'w')
comparisonFileiBubble = open("iBubbleComparison.txt", 'w')
comparisonFileinsertion = open("InsertionComparison.txt", 'w')
comparisonFileselection = open("SelectionComparison.txt", 'w')
comparisonFilemerge = open("MergeComparison.txt", 'w')
comparisonFilequick = open("QuickComparison.txt", 'w')

print("\n\n Comparisons started \n\n")

for i in range(30, 1001, 10):
    comparison_bubble = 0
    comparison_ibubble = 0
    comparison_insertion = 0
    comparison_selection = 0
    comparison_merge = 0
    comparison_quick = 0

    print("\n\t\t\t------- Sortings going on -------\n")

    for j in range(1, 6):

        fileName = "files/Data_Size=" + str(i) + "_Var=" + str(j) + ".txt"

        # retrieve data from files
        file = open(fileName, 'r')
        array = file.read().splitlines()
        numbers4 = list(map(int, array))
        # numbers1=array[:]
        # numbers2=array[:]
        # numbers3=array[:]
        # numbers4=array[:]
        # numbers5=array[:]

        # comparison_bubble+=bubblesort(numbers)                              # start sorting
        # comparison_ibubble+=ibubblesort(numbers1)
        # comparison_insertion+=insertionsort(numbers2)
        # comparison_selection+=selectionsort(numbers3)
        # comparison_merge += mergeSort(numbers4)
        comparison_quick+=quicksort(number4,0,len(whytirun-1)

      #   file = open(fileName, 'w')
      #   file.write("\n".join(str(numbers4)))
      #   file.close()

    # comparisonFileBubble.write(str(comparison_bubble//5)+"\n")                # find avg for n input size
    # comparisonFileiBubble.write(str(comparison_ibubble//5)+"\n")
    # comparisonFileinsertion.write(str(comparison_insertion//5)+"\n")
    # comparisonFileselection.write(str(comparison_selection//5)+"\n")
    comparisonFilemerge.write(str(comparison_merge // 5) + "\n")
    # comparisonFilequick.write(str(comparison_quick//5)+"\n")

# comparisonFileBubble.close()
# comparisonFileiBubble.close()
# comparisonFileinsertion.close()
# comparisonFileselection.close()
comparisonFilemerge.close()
# comparisonFilequick.close()

print("\n\n Comparisons Done \n\n")
