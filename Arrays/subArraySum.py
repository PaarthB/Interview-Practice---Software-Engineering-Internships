'''
Facebook final interview question for SWE Internship
'''
def findSumInterval(array, value):
    n = len(array)
    first = 0
    sum_curr = array[0]
      
    if sum_curr == value:
        return True

    for j in range(1, n):
        if array[j] > value:
            first = j + 1
            sum_curr = 0
            continue

        sum_curr += array[j]

        while sum_curr > value:
            sum_curr -= array[first]
            first += 1

        if sum_curr < value:
            continue

        elif sum_curr == value:
            return True

    return False

print(findSumInterval([1, 2, 2, 4, 8], 6))
