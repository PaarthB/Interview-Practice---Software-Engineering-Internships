'''
Returns all the different combinations from a binary string by replacing wildcard characters '?'
For example, for input 10?011, it returns ['101011', '100011']
'''
def returnPermutations(inputString):
    count = 0
    permutations = []
    position = []
    
    for i in range(len(inputString)):
        if inputString[i] == "?":
            position.append(i)
            count += 1
            
    for j in range(0, 1 << count):
        temp = j  # 0, 1
        listM = list(inputString)
        for k in position:  # [1]
            bit = temp & 1  # (1 & 1) = 1
            listM[k] = str(bit)  # 000, 010
            temp >>= 1
        permutations.append(''.join(listM))
        
    return permutations
