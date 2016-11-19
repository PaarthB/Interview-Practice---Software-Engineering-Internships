__author__ = 'Paarth Bhasin'

'''
Function: find_max_sum_interval(a_list):

    Preconditions: a_list contains only numbers
    Postconditions: We get the interval in a_list which has the maximum sum.

    TEST CASES:
        VALID TEST CASES: a_list is a list which contains only integers
            Input:
                [-1,-2,3,-14]

            Output:
                Maximum Sum: 3
                Sliced List: 3
                Start: 2
                End: 2
        INVALID TEST CASES: a_list doesn't contain only integers
                Input:
                    ['b',1,2,'c']

                Output:
                    unsupported operand type(s) for +=: 'int' and 'str'

    Best Case Complexity: O(N)
    Worst Case Complexity: O(N^2)
'''

import random
import time


def find_max_sum_interval(a_list):
    max = 0
    min = 0
    sum_max = a_list[0]
    n = len(a_list)
    a = []
    summed = False

    for i in range(0, n):
        sum = a_list[i]
        if sum > sum_max:
            sum_max = sum
        for j in range(i + 1, n):
            sum += a_list[j]
            if sum > sum_max:
                sum_max = sum
                # Meaning there are negative numbers prior to a_list[j] which should be neglected.
                if a_list[j] > sum_max:
                    sum_max = a_list[j]
                    a = a_list[j]
                    max = j
                    min = j
                else:
                    a = a_list[min:max + 1]
                    max = j
                    min = i
                summed = True
            if summed == False and a_list[j] > sum_max:
                a = a_list[j]
                sum_max = a_list[j]
                max = j
                min = j
            elif summed == False:
                a = a_list[0]
        a = a_list[min:max + 1]

    print('Maximum Sum:', sum_max)
    print('Sliced List:', a)
    print('Start:', min)
    print('End:', max)

a = [1, 2, 3, 4]

find_max_sum_interval(a)
