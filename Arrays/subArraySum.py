
def findSumInterval(array, sum):
   n = len(array)
   first = 0
   sum = array[0]
   sum_curr = sum
   if sum_curr == value:
     return True

   for j in range(1, n):
     if array[j] > value:
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
