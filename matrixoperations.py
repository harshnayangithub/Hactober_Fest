

def add_matrices(matrix1, matrix2):
    result = []
    for i in range(len(matrix1)):
        row = []
        for j in range(len(matrix1[0])):
            row.append(matrix1[i][j] + matrix2[i][j])
        result.append(row)
    return result

def subtract_matrices(matrix1, matrix2):
    result = []
    for i in range(len(matrix1)):
        row = []
        for j in range(len(matrix1[0])):
            row.append(matrix1[i][j] - matrix2[i][j])
        result.append(row)
    return result

def multiply_matrices(matrix1, matrix2):
    result = []
    for i in range(len(matrix1)):
        row = []
        for j in range(len(matrix2[0])):
            sum = 0
            for k in range(len(matrix2)):
                sum += matrix1[i][k] * matrix2[k][j]
            row.append(sum)
        result.append(row)
    return result

def transpose_matrix(matrix):
    result = [[matrix[j][i] for j in range(len(matrix))] for i in range(len(matrix[0]))]
    return result

while True:
    print("Menu:")
    print("1. Input matrix")
    print("2. Addition of two matrices")
    print("3. Subtraction of two matrices")
    print("4. Multiplication of two matrices")
    print("5. Transpose matrix")
    print("6. Exit")

    choice = int(input("Enter your choice: "))

    if choice == 1:
        matrix1 = input_matrix()
    elif choice == 2:
        matrix2 = input_matrix()
        if len(matrix1) != len(matrix2) or len(matrix1[0]) != len(matrix2[0]):
            print("Matrix dimensions must be the same for addition.")
        else:
            result = add_matrices(matrix1, matrix2)
            print("Result of addition:")
            for row in result:
                print(row)
    elif choice == 3:
        matrix2 = input_matrix()
        if len(matrix1) != len(matrix2) or len(matrix1[0]) != len(matrix2[0]):
            print("Matrix dimensions must be the same for subtraction.")
        else:
            result = subtract_matrices(matrix1, matrix2)
            print("Result of subtraction:")
            for row in result:
                print(row)
    elif choice == 4:
        matrix2 = input_matrix()
        if len(matrix1[0]) != len(matrix2):
            print("Number of columns in the first matrix must be equal to the number of rows in the second matrix for multiplication.")
        else:
            result = multiply_matrices(matrix1, matrix2)
            print("Result of multiplication:")
            for row in result:
                print(row)
    elif choice == 5:
        result = transpose_matrix(matrix1)
        print("Transpose of the matrix:")
        for row in result:
            print(row)
    elif choice == 6:
        break
    else:
        print("Invalid choice. Please enter a valid option.")






