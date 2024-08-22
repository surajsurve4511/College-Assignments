'''
Title: - Python program to perform operations on Matrix.

Aim: - Write a python program to compute following computation on matrix:

a) Addition of two matrices

b) Subtraction of two matrices

c) Multiplication of two matrices

d) Transpose of a matrix
'''

def take_input(matrix):
    def take_input_MATRIX(matrix):
     print("Enter the elements of the matrix")
     for i in range(len(matrix)):
        for j in range(len(matrix[0])):
            matrix[i][j] = int(input(f"Enter element [{i}][{j}]: "))
     return matrix
    matrix1_rows = int(input("Enter number of rows for matrix 1: "))
    matrix1_cols = int(input("Enter number of columns for matrix 1: "))
    matrix1 = [[0] * matrix1_cols for _ in range(matrix1_rows)]
    take_input_MATRIX(matrix1)

    matrix2_rows = int(input("Enter number of rows for matrix 2: "))
    matrix2_cols = int(input("Enter number of columns for matrix 2: "))
    matrix2 = [[0] * matrix2_cols for _ in range(matrix2_rows)]
    take_input_MATRIX(matrix2)

def add(matrix1, matrix2):
    if len(matrix1) != len(matrix2) or len(matrix1[0]) != len(matrix2[0]):
        raise ValueError("Matrix dimensions must be the same for addition")

    result = [[0] * len(matrix1[0]) for _ in range(len(matrix1))]
    for i in range(len(matrix1)):
        for j in range(len(matrix1[0])):
            result[i][j] = matrix1[i][j] + matrix2[i][j]

    return result

def subtract(matrix1, matrix2):
    if len(matrix1) != len(matrix2) or len(matrix1[0]) != len(matrix2[0]):
        raise ValueError("Matrix dimensions must be the same for subtraction")

    result = [[0] * len(matrix1[0]) for _ in range(len(matrix1))]
    for i in range(len(matrix1)):
        for j in range(len(matrix1[0])):
            result[i][j] = matrix1[i][j] - matrix2[i][j]

    return result

def multiply(matrix1, matrix2):
    if len(matrix1[0]) != len(matrix2):
        raise ValueError("Number of columns in matrix1 must be equal to number of rows in matrix2 for multiplication")

    for i in range(len(matrix1[0])):
        for j in range(len(matrix2[0])):
            for k in range(len(matrix2)):
                result[i][j] += matrix1[i][k] * matrix2[k][j]

    return result

def transpose(matrix):
    result = [[matrix[j][i] for j in range(len(matrix))] for i in range(len(matrix[0]))]
    return result

print("Welcome to matrix operations")
print("1. Addition of two matrices")
print("2. Subtraction of two matrices")
print("3. Multiplication of two matrices")
print("4. Transpose of a matrix")
choice = int(input("Enter ur choice"))

if choice == 1 or choice == 2:
    matrix1 = take_input(matrix)
    matrix2 = take_input(matrix)

    if choice == 1:
        try:
            result = add(matrix1, matrix2)
            print("Addition of two matrices: ", result)
        except ValueError as e:
            print(e)
    elif choice == 2:
        try:
            result = subtract(matrix1, matrix2)
            print("Subtraction of two matrices: ", result)
        except ValueError as e:
            print(e)

elif choice == 3:
    matrix1 = take_input(matrix)
    matrix2 = take_input(matrix)
    try:
        result = multiply(matrix1, matrix2)
        print("Multiplication of two matrices: ", result)
    except ValueError as e:
        print(e)

elif choice == 4:
    matrix1 = take_input(matrix)
    matrix2 = take_input(matrix)
    result = transpose(matrix1)
    result = transpose(matrix2)
    print("Transpose of a matrix: ", result)

else:
    print("Invalid choice")
