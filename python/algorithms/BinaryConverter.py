
def convertToBinary(integer):
    if integer == 0:
        return ""
    else:
        return str(convertToBinary(int(integer/2))) + str(integer % 2)
