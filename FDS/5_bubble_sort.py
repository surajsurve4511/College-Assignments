#BUBBLE SORT

from typing import Counter
def bubble_sort(arr1):
  num1 = len(arr1)
  Counter = 0
  for i in range(num1):
    for j in range(0, num1 - i - 1):
      if arr1[j] > arr1[j + 1]:

        temp_var = arr1[j]
        arr1[j] = arr1[j+1]
        arr1[j+1] = temp_var
      Counter+=1
  print("The number of swaps are: ", Counter)
  return arr1
bubble_sort(arr)
print(arr)
