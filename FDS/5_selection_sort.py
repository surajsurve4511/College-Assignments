#SELECTION SORT
n = int(input("Enter the size of the array: "))
arr = []
def input_array(arr):
  for i in range(n):
   arr.append(int(input(f"Enter element {i+1}: ")))
  return arr
input_array(arr)
print("The array is: ", arr)



def selection_sort(arr):
  count = 0
  for i in range(len(arr)):
    for j in range(i + 1, len(arr)):
      if arr[i]>arr[j]:
        arr[i], arr[j] = arr[j], arr[i]
      count+=1
  print("The number of swaps are: ", count)
  return arr
print(selection_sort(arr))
