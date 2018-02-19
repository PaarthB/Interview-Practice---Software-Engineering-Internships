__author__ = 'Paarth Bhasin'

"""
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

Function: average_time_find_max_interval()

    Preconditions: None
    Postconditions: We get the average time taken to find max sum interval in a list of N elements
                    (N = 2,4,8,16....1024).
    TEST CASES:

        VALID TEST CASE: all
            a_list: A list of real numbers between 0 and 1.

            Output:
                n: 32
                Average Time: 0.00013000965118408202

                n: 64
                Average Time: 0.0008400797843933106

        INVALID TEST CASE: None

    Best Case Complexity: O(N)
    Worst Case Complexity: O(N^2)

Function: time_find_max_interval(a_list)

    VALID TEST CASE: When a_list contains only numbers
        Inputs: [1,2,3,4]

        Ouput: Time taken for finding max interval: 0.0

    INVALID TEST CASE: When list doesn't contain only numbers
        Inputs: ['b',1,4,3]

        Output: unsupported operand type(s) for +=: 'int' and 'str'

    Best Case Complexity: O(N)
    Worst Case Complexity: O(N^2)
    N: length of a_list
"""

import random
import time


def find_max_sum_interval(a_list):
    max = 0
    min = 0
    sum_max = a_list[0]
    n = len(a_list)
    a = []
    summed = False
    i = 0
    # for i in range(0, n):
    sum = sum_max
    
    for j in range(1, n):
        sum += a_list[j]
        if a_list[j] > sum:
            sum = a_list[j]
            i = j

        if sum > sum_max:
            sum_max = sum
            # Meaning there are negative numbers prior to a_list[j] which should be neglected.
            max = j
            min = i

        print(sum_max)

    a = a_list[min:max + 1]

    print('Maximum Sum:', sum_max)
    print('Sliced List:', a)
    print('Start:', min)
    print('End:', max)


def average_time_find_max_interval():
    for j in range(1, 11):
        count = 0
        n = 2 ** j
        time = 0
        while count < 10:
            a = []
            for i in range(n):
                a.append(random.random())
                time += time_find_max_interval(a)
            count += 1
        print('n:', n)
        average_time = time / 100
        print('Average Time:', average_time)


def time_find_max_interval(a_list):
    start = time.time()
    find_max_sum_interval(a_list)
    taken = (time.time() - start)
    return taken


a = [1, 8, 20, 20, 113, 2, 2, 1, 101, 50, 12]

find_max_sum_interval(a)
