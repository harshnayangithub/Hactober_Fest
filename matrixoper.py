def add_matrices(matrix1, matrix2):
    return [[matrix1[i][j] + matrix2[i][j] for j in range(len(matrix1[0]))] for i in range(len(matrix1))]


def subtract_matrices(matrix1, matrix2):
    return [[matrix1[i][j]-matrix2[i][j] for j in range(len(matrix1[0]))] for i in range(len(matrix1))]
   # result=[]
   # for i in range(len(matrix1)):
   #     row=[]
   #     for j in range(len(matrix1[0])):
    #        row.append(matrix1[i][j]-matrix2[i][j])
    #   result.append(row)
    # return result


def multiply_matrices(matrix1, matrix2):
    result = [[0 for j in range(len(matrix2[0]))]
              for i in range(len(matrix1))]  # ultra important

    if (len(matrix1[0]) == len(matrix2)):
        for i in range(len(matrix1)):
            for j in range(len(matrix2[0])):
                for k in range(len(matrix2)):
                    result[i][j] += matrix1[i][k] * matrix2[k][j]
    else:
        print("Multiplication not possible")
    return result


def transpose_matrix(matrix):
    # Create a new matrix with dimensions swapped
    transposed_matrix = [[matrix1[j][i] for j in range(
        len(matrix1))]for i in range(len(matrix1[0]))]
    return transposed_matrix


def display_matrix(matrix):
    for row in matrix:
        print(row)


def get_matrix_from_user(rows, cols):
    matrix = []
    for i in range(rows):
        row = [int(x) for x in input(
            f"Enter values for row {i + 1} (comma-separated): ").split(',')]
        if len(row) != cols:
            print("Invalid input. Please enter the correct number of columns.")
            return None
        matrix.append(row)
    return matrix


rows1 = int(input("Enter the number of rows for matrix1: "))
cols1 = int(input("Enter the number of columns for matrix1: "))
matrix1 = get_matrix_from_user(rows1, cols1)

rows2 = int(input("Enter the number of rows for matrix2: "))
cols2 = int(input("Enter the number of columns for matrix2: "))
matrix2 = get_matrix_from_user(rows2, cols2)


while True:
    print("\n------ Menu ------")
    print("1. Addition of two matrices")
    print("2. Subtraction of two matrices")
    print("3. Multiplication of two matrices")
    print("4. Transpose of a matrix")
    print("5. Exit")

    choice = int(input("Enter your choice (1-5): "))

    if choice == 1:
        result = add_matrices(matrix1, matrix2)
        print("\nResult of addition:")
        display_matrix(result)

    elif choice == 2:
        result = subtract_matrices(matrix1, matrix2)
        print("\nResult of subtraction:")
        display_matrix(result)

    elif choice == 3:
        result = multiply_matrices(matrix1, matrix2)
        print("\nResult of multiplication:")
        display_matrix(result)

    elif choice == 4:
        result = transpose_matrix(matrix1)
        print("\nTranspose of the first matrix:")
        display_matrix(result)

    elif choice == '5':
        print("Exiting the program. Goodbye!")
        break

    else:
        print("Invalid choice. Please enter a number between 1 and 5.")
