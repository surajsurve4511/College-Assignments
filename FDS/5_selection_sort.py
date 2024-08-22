#SELECTION SORT
n = int(input("Enter the size of the array: "))
arr = []
def input_array(arr):
  for i in range(n):
   arr.append(int(input(f"Enter element {i+1}: ")))
  return arr
input_array(arr)
print("The array is: ", arr)
