# List Flattening algorithm
# Takes in an array of any dimension and converts it to a 1-D array
# 
def makeFlat(arr):
  i = 0
  while i < len(arr):
    while True:
      try:
        arr[i:i+1] = arr[i]
      except (TypeError, IndexError):
        break
    i += 1

def main():
  test = [[1, 2], 3, [[4], 5], 6, 7, [[8, []]]]
  makeFlat(test)
  print(test)

if __name__ == '__main__':
  main()
