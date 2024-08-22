# QUICKSORT

#taking array as input from user

n = int(input("Enter number of entries: "))
arr = []

for i in range(n):
  element = int(input("Enter the element: "))
  arr.append(element)

print(arr)

#defining function for quick sort

left_most = 0
right_most = len(arr)-1


def partition(arr , left_most , right_most):
  pivot = arr[right_most]
  i = left_most - 1

  for j in range(left_most , right_most):
    if arr[j] <= pivot:
      i = i + 1
      arr[i] , arr[j] = arr[j] , arr[i]

  arr[i+1] , arr[right_most] = arr[right_most] , arr[i+1]

  return i + 1

def quick_sort(arr , left_most , right_most):
  if left_most < right_most:
    pi = partition(arr , left_most , right_most)
    quick_sort(arr , left_most , pi-1)
    quick_sort(arr , pi+1 , right_most)

quick_sort(arr , left_most , right_most)

print(arr)
