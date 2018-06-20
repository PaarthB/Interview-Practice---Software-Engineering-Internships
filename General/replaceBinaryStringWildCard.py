"
Returns all the different combinations from a binary string by replacing wildcard characters '?'
For example, for input 10?011, it returns ['101011', '100011']
"
def returnPermutations(inputString):
    count = 0
    permutations = []
    index = 0
    position = []
    for i in inputString:
        if inputString[i] == "?":
            position.append(i)
            count += 1
        index += 1
    end = 1 << count
    for j in range(0, end):
        temp = j  # 0, 1
        listM = list(inputString)
        for k in position:  # [1]
            bit = temp & 1  # (1 & 1) = 1
            listM[k] = str(bit)  # 000, 010
            temp >>= 1
        permutations.append(''.join(listM))

    return permutations
